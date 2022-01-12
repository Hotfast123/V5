// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ObjectToSlice.generated.h"

UCLASS()
class V5_API AObjectToSlice : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObjectToSlice();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// This is called when actor is spawned (at runtime or when you drop it into the world in editor)
	void PostActorCreated();
	void PostLoad();
	void CreateTriangle();

private:
	UPROPERTY(VisibleAnywhere)
		UProceduralMeshComponent* mesh;
};
