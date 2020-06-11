// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "Math/RandomStream.h"
#include "DrawDebugHelpers.h"
#include "RoomInstance.h"
#include "Engine/World.h"
#include "Math/Vector.h"
#include "CoreMinimal.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/Actor.h"
#include "DungeonManager.generated.h"

class USceneComponent;
class ARoomInstance;

UCLASS()
class ROGUELIKE3D_API ADungeonManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADungeonManager();

	UPROPERTY(EditAnywhere, Category = "Defaults")
		int32 MaxRooms;
	UPROPERTY(EditAnywhere, Category = "Defaults")
		int32 Seed;
	UPROPERTY(VisibleAnywhere, Category = "Defaults")
		FRandomStream RandomSeed;

	UPROPERTY(EditAnywhere, Category = "Defaults")
		TArray<TSubclassOf<ARoomInstance>> RoomTypes;

	UPROPERTY(EditAnywhere, Category = "Defaults")
		TArray<ARoomInstance*> SpawnedRooms;
		
	UFUNCTION(CallInEditor, Category = "Defaults")
		void CheckRooms();
	
	void SpawnRooms();

	class USceneComponent* SceneRoot;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
