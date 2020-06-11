// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DungeonSpawner.generated.h"

UCLASS()
class ROGUELIKE3D_API ADungeonSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADungeonSpawner();
	
	UPROPERTY(EditAnywhere, Category = "Defaults")
		int32 Cols;
	UPROPERTY(EditAnywhere, Category = "Defaults")
		int32 Rows;
	UPROPERTY(EditAnywhere, Category = "Defaults")
		int32 Scale;
	UPROPERTY(EditAnywhere, Category = "Defaults")
		int32 MaxRooms;
	UPROPERTY(EditAnywhere, Category = "Defaults")
		int32 RndSeed;
	UPROPERTY(EditAnywhere, Category = "Defaults")
		TArray<UStaticMeshComponent*> RoomTypes;
	UPROPERTY(VisibleAnywhere, Category = "Defaults")
		TArray<UStaticMeshComponent*> RoomList;
	UFUNCTION(CallInEditor, Category = "Defaults")
		void SpawnRooms();
	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent* SMComp;
	class USceneComponent* SceneRoot;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;

	//UPROPERTY()

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
