// Fill out your copyright notice in the Description page of Project Settings.


#include "DungeonManager.h"

// Sets default values
ADungeonManager::ADungeonManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	SetRootComponent(SceneRoot);

}

void ADungeonManager::CheckRooms()
{
	//get rid of any rooms that currently exists
	ARoomInstance* NewRoom;
	FlushPersistentDebugLines(GetWorld());
	if (SpawnedRooms.Num() > 0)
	{
		for (ARoomInstance* Room : SpawnedRooms)
		{
			Room->Destroy();
		}
	}
	SpawnedRooms.Empty();
	
	//spawn the very first room as the very first element in the array
	FActorSpawnParameters SpawnParams;
	if (SpawnedRooms.Num() < MaxRooms)
	{
		if (SpawnedRooms.Num() <= 0)
		{
			NewRoom = GetWorld()->SpawnActor<ARoomInstance>(RoomTypes[0], GetActorLocation(), GetActorRotation(), SpawnParams);
			SpawnedRooms.Add(NewRoom);
			SpawnedRooms[0]->CheckOverlaps(SpawnedRooms);
			SpawnRooms();
		}
	}


}
void ADungeonManager::SpawnRooms()
{
	UE_LOG(LogTemp, Warning, TEXT("Room Count At Rec Loop Start: %i"), SpawnedRooms.Num());
	RandomSeed.Initialize(Seed);
	ARoomInstance* NewRoom;
	TArray<ARoomInstance*> TempRooms;
	FActorSpawnParameters SpawnParams;
	UE_LOG(LogTemp, Warning, TEXT("Else Started"));
	//	go through every room in the spawned rooms array
	if (SpawnedRooms.Num() < MaxRooms)
	{
		for (ARoomInstance* Room : SpawnedRooms)
		{
			UE_LOG(LogTemp, Warning, TEXT("Room: %s"), *GetNameSafe(Room));
			//	check if any of the rooms are overlapping and where a new room can be spawned
			Room->CheckOverlaps(SpawnedRooms);

			//////////////////////////////////////////////////////////////////
			//	for every arrow in the arrows array of every room instance	//
			//	spawn a new room at said arrow's location and add the new	//
			//	room to a temp array so we can add it to the spawned rooms	//
			//	array later without errors about range based loops changing	//
			//////////////////////////////////////////////////////////////////
			for (UArrowComponent* Arrow : Room->Arrows)
			{
				//FRotator LookAtRot = UKismetMathLibrary::FindLookAtRotation(Arrow->GetComponentLocation(), Room->GetActorLocation());
				UE_LOG(LogTemp, Warning, TEXT("Arrow: %s"), *GetNameSafe(Arrow));
				NewRoom = GetWorld()->SpawnActor<ARoomInstance>(RoomTypes[RandomSeed.FRandRange(0, RoomTypes.Num())], Arrow->GetComponentLocation(), Arrow->GetComponentRotation(), SpawnParams);
				TempRooms.Add(NewRoom);
			}
		}

		//	go through every room in the temp rooms array and add it to the
		//	spawned rooms array and check for overlaps again just incase
		for (ARoomInstance* Room : TempRooms)
		{
			UE_LOG(LogTemp, Warning, TEXT("Room: %s"), *GetNameSafe(Room));
			SpawnedRooms.Add(Room);
			Room->CheckOverlaps(SpawnedRooms);
		}
		UE_LOG(LogTemp, Warning, TEXT("Room Count At Rec Loop End: %i"), SpawnedRooms.Num());
	
		SpawnRooms();
	}
	else if (SpawnedRooms.Num() > MaxRooms)
	{
		for (int32 i = SpawnedRooms.Num() - 1; i > 0; i--)
		{
			if (SpawnedRooms.Num() > MaxRooms)
			{
				SpawnedRooms[i]->Destroy();
				SpawnedRooms.RemoveAt(i);
			}
		}
		/*SpawnedRooms.Remove(SpawnedRooms.Last()-1);
		SpawnedRooms.Pop();
		SpawnedRooms.Shrink();
		//SpawnedRooms.RemoveAt(SpawnedRooms.Num()-1);
		SpawnedRooms.Last()->Destroy();*/
		SpawnRooms();
	}
}

// Called when the game starts or when spawned
void ADungeonManager::BeginPlay()
{
	Super::BeginPlay();
	CheckRooms();
}

// Called every frame
void ADungeonManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

