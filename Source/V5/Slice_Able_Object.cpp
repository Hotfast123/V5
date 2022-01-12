// Fill out your copyright notice in the Description page of Project Settings.


#include "Slice_Able_Object.h"

// Sets default values
ASlice_Able_Object::ASlice_Able_Object()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASlice_Able_Object::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASlice_Able_Object::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

