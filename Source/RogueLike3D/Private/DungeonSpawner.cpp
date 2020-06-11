// Fill out your copyright notice in the Description page of Project Settings.

#include "DungeonSpawner.h"
#include "Components/StaticMeshComponent.h"
//#include "Engine/StaticMesh.h"

// Sets default values
ADungeonSpawner::ADungeonSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*//v1 spawn rooms and hallways together randomly
	while (bHasNoExit)
	{
		//random int in range
		int maxRoomsCount
		int currentRoomsCount
		if curRoomsCount != MaxRoomsCount
			//switch on int
				spawn random room
				for each room socket
					spawn new room until dead end/exit room reached
			if room is exit
				set hasnoexit to false
		else
			spawn exit
			set hasnoexit to false
	}

	//v2 spawn rooms first ask questions later
	int maxRooms
	int curRooms

	//v3 winging it
	array of meshes to spawn //(0 = empty, rest = meshes)
	int number of rooms
	*/

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	SetRootComponent(SceneRoot);
	Rows = 10;
	Cols = 10;
	FName InitialName = FName("MyCompName");
	for (int32 r = 0; r < Rows; r++)
	{
		for (int32 c = 0; c < Cols; c++)
		{
			UPROPERTY(VisibleAnywhere)
				UStaticMeshComponent* NewComp = CreateDefaultSubobject<UStaticMeshComponent>(InitialName);

			FString Str = "MyCompName_" + FString::FromInt(r) + "_" + FString::FromInt(c);
			InitialName = (*Str);
			/*RoomList.Add(NewComp);
			if (NewComp)
			{

				//Register the new component
				//NewComp->AttachTo(this->RootComponent);
				//SMComp->SetupAttachment(RootComponent,"AttachSocketName");
				//NewComp->SetStaticMesh(nullptr);
				//NewComp->RegisterComponent();
				//NewComp->AttachTo(GetRootComponent(), NAME_None, EAttachLocation::KeepRelativeOffset);
				//Set the static mesh of our component
				NewComp->StaticMesh = SM->StaticMesh;


				//Set a random location based on the values we enter through the editor
				FVector Location;
				//Set the random seed in case we need to change our random values
				FMath::SRandInit(RandomSeed);

				Location.X += FMath::RandRange(-FMath::Abs(XThreshold), FMath::Abs(XThreshold));
				Location.Y += FMath::RandRange(-FMath::Abs(YThreshold), FMath::Abs(YThreshold));

				NewComp->SetWorldLocation(Location);

				//Attach the component to the root component
				NewComp->AttachTo(GetRootComponent(), NAME_None, EAttachLocation::KeepRelativeOffset);
			}*/
		}
	}
}



void ADungeonSpawner::SpawnRooms()
{

}


void ADungeonSpawner::OnConstruction(const FTransform & Transform)
{
	//RegisterAllComponents();
	/*FName InitialName = FName("MyCompName");
	for (int32 r = 0; r < Rows; r++)
	{
		for (int32 c = 0; c < Cols; c++)
		{
			UStaticMeshComponent* NewComp = NewObject<UStaticMeshComponent>(RootComponent,InitialName);
			FString Str = "MyCompName_" + FString::FromInt(r) + "_" + FString::FromInt(c);
			InitialName = (*Str);

			if (NewComp)
			{

				//Register the new component
				NewComp->AttachTo(this->RootComponent);
				NewComp->RegisterComponent();
				//NewComp->AttachTo(GetRootComponent(), NAME_None, EAttachLocation::KeepRelativeOffset);
				//Set the static mesh of our component
				NewComp->StaticMesh = SM->StaticMesh;


				//Set a random location based on the values we enter through the editor
				FVector Location;
				//Set the random seed in case we need to change our random values
				FMath::SRandInit(RandomSeed);

				Location.X += FMath::RandRange(-FMath::Abs(XThreshold), FMath::Abs(XThreshold));
				Location.Y += FMath::RandRange(-FMath::Abs(YThreshold), FMath::Abs(YThreshold));

				NewComp->SetWorldLocation(Location);

				//Attach the component to the root component
				NewComp->AttachTo(GetRootComponent(), NAME_None, EAttachLocation::KeepRelativeOffset);
			}
		}
	}*/
}
	
// Called when the game starts or when spawned
void ADungeonSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADungeonSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

