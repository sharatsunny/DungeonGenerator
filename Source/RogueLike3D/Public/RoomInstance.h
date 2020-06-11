// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EngineGlobals.h"
#include "Engine/Engine.h"
#include "DrawDebugHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "RoomInstance.generated.h"

class UArrowComponent;
class UStaticMeshComponent;
//class ADungeonManager;

UCLASS()
class ROGUELIKE3D_API ARoomInstance : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARoomInstance();
	
	UPROPERTY(VisibleAnywhere, Category = "Defaults")
		UStaticMeshComponent* BaseMesh;
	UFUNCTION()
		void CheckOverlaps(TArray<ARoomInstance*>& SpawnedRooms);
	UPROPERTY(EditAnywhere, Category = "Connections")
		TArray<UArrowComponent*> Arrows;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
