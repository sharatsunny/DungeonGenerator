// Fill out your copyright notice in the Description page of Project Settings.


#include "RoomInstance.h"

// Sets default values
ARoomInstance::ARoomInstance()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RootComp"));
	SetRootComponent(BaseMesh);
}

void ARoomInstance::CheckOverlaps(TArray<ARoomInstance*>& SpawnedRooms)//ARoomInstance* Rooms)
{
	//////////////////////////////////////////////////////////////////////
	//	this array will be used to hold a list of arrows we want to		//
	//	delete because otherwise we'll run into an error when the		//
	//	default arrows array gets changed during the range based loop	//
	//////////////////////////////////////////////////////////////////////
	TArray<UArrowComponent*> ArrowsToDelete;
	GetComponents<UArrowComponent>(Arrows);


	/*for (int32 i = Arrows.Num() - 1; i > 0; i--)
	{
		bool bIsWallArrow = Arrows[i]->ComponentHasTag(TEXT("Walls"));
		if (bIsWallArrow)
		{
			Arrows.RemoveAt(i);
		}
	}*/

	//	loop through all the arrows in the instance of this actor/class
	for (UArrowComponent* Arrow : Arrows)
	{
		FColor rndColor = FColor::MakeRandomColor();
		bool bCheckRoomOverlap;
		bool bCheckArrowOverlap;

		DrawDebugLine(GetWorld(), Arrow->GetComponentLocation(), Arrow->GetComponentLocation() + FVector(0.0f, 0.0f, 500.0f), FColor::White, true, -1.0f, 0, 20.0f);
		//	then loop through all the rooms in the spawned rooms array we passed through
		for (ARoomInstance* Room : SpawnedRooms)
		{
			//	compare the location of every arrow in the instance with every room in the level to see if it is overlapping
			bCheckRoomOverlap = Arrow->GetComponentLocation().Equals(Room->GetActorLocation(), 150.0f) || !Arrow->ComponentHasTag(TEXT("RoomSpawnPoint"));

			//	if the arrow is overlapping a room then add it to the arrows to delete array
			if (bCheckRoomOverlap)
			{
				//DrawDebugLine(GetWorld(), Arrow->GetComponentLocation(), Arrow->GetComponentLocation() + FVector(0.0f, 0.0f, 500.0f), FColor::Green, true, -1.0f, 0, 20.0f);
				ArrowsToDelete.Add(Arrow);
			}
			/*else
			{
				DrawDebugLine(GetWorld(), Arrow->GetComponentLocation(), Arrow->GetComponentLocation() + FVector(0.0f, 0.0f, -500.0f), FColor::Red, true, -1.0f, 0, 20.0f);
			}*/

			//	loop through every arrow in every other room that's in the level
			for (UArrowComponent* ArrowAgainst : Room->Arrows)
			{
				//	this check is so that the arrow doesn't check against itself
				//	because it will always be true and will add every arrow to the
				//	arrows to delete array
				if (Arrow != ArrowAgainst)
				{
					//	check if the arrow is overlapping with another arrow so that we don't accidentally spawn 2 rooms in the same place
					bCheckArrowOverlap = Arrow->GetComponentLocation().Equals(ArrowAgainst->GetComponentLocation(), 50.0f);

					//UE_LOG(LogTemp, Warning, TEXT("----------------------------------------------------"));
					//UE_LOG(LogTemp, Warning, TEXT("Overlapping?: %s , Overlap obj: %s , Arrow: %s , ArrowAgainst: %s"), (bCheckArrowOverlap ? TEXT("True") : TEXT("False")), *GetNameSafe(Room), *GetNameSafe(Arrow), *GetNameSafe(ArrowAgainst));

					if (bCheckArrowOverlap)
					{
						//DrawDebugLine(GetWorld(), Arrow->GetComponentLocation(), Arrow->GetComponentLocation() + FVector(0.0f, 0.0f, 500.0f), FColor::Green, true, -1.0f, 0, 20.0f);
						ArrowsToDelete.Add(Arrow);
					}
					/*else
					{
						DrawDebugLine(GetWorld(), Arrow->GetComponentLocation(), Arrow->GetComponentLocation() + FVector(0.0f, 0.0f, -500.0f), FColor::Red, true, -1.0f, 0, 20.0f);
					}*/
				}
			}
		}
	}
	/*for (int32 i = Arrows.Num() - 1; i > 0; i--)
	{
		bool bIsWallArrow = Arrows[i]->ComponentHasTag(TEXT("Walls"));
		if (bIsWallArrow)
		{
			Arrows.RemoveAt(i);
		}
	}*/
	//	finally go through every arrow in the arrows to delete array
	//	and destroy the component if possible and remove them from
	//	the array so that a new room won't be spawned on that arrow
	for (UArrowComponent* Arrow : ArrowsToDelete)
	{
		if(Arrow->ComponentHasTag(TEXT("Walls")))
		{
			Arrows.Remove(Arrow);
		}
		else
		{
			Arrow->DestroyComponent();
			Arrows.Remove(Arrow);
		}
		UE_LOG(LogTemp, Warning, TEXT("Arrows: %s"), *GetNameSafe(Arrow));
	}
}

// Called when the game starts or when spawned
void ARoomInstance::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ARoomInstance::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

