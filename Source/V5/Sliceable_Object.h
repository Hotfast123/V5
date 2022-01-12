// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "Sliceable_Object.generated.h"

class UBoxComponent;

UCLASS()
class V5_API ASliceable_Object : public AActor
{
	GENERATED_BODY()

	UPROPERTY()
	UProceduralMeshComponent* ProcMesh;
	void CreateMesh();
public:	
	// Sets default values for this actor's properties
	ASliceable_Object();

protected:
	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UMaterialInterface* Material;
public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, category = "compontents");
	UBoxComponent* Hitbox;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};
