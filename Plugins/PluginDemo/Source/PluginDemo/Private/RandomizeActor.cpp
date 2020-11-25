// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomizeActor.h"

// Sets default values
ARandomizeActor::ARandomizeActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	numMap = TMap<int32, float>();
	interval = 2;
	currentTime = interval;
}

// Called when the game starts or when spawned
void ARandomizeActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARandomizeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	currentTime -= DeltaTime;

	if (currentTime <= 0) {
		UE_LOG(LogTemp, Warning, TEXT("Num: %d"), GetVal());
		currentTime = interval;
	}

}

float ARandomizeActor::GetSumOfWeights() {
	float sum = 0;
	for (TPair<int32, float> pair : numMap) {
		sum += pair.Value;
	}

	return sum;
}

void ARandomizeActor::AddValue(int32 val, float weight) {
	numMap.Add(val, weight);
}

void ARandomizeActor::RemoveValue(int32 val) {
	if (numMap.Contains(val)) {
		numMap.FindAndRemoveChecked(val);
	}
}

int32 ARandomizeActor::GetVal() {
	float rand = FMath::RandRange(0.0f, GetSumOfWeights());

	for (TPair<int32, float> pair : numMap) {
		rand -= pair.Value;
		if (rand <= 0) {
			return pair.Key;
		}
	}
	return 0;
}

