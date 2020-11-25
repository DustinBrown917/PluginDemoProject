// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RandomizeActor.generated.h"

UCLASS()
class PLUGINDEMO_API ARandomizeActor : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere)
	TMap<int32, float> numMap;

	// Sets default values for this actor's properties
	ARandomizeActor();

protected:
	float interval;
	float currentTime;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual float GetSumOfWeights();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void AddValue(int32 val, float weight);
	virtual void RemoveValue(int32 val);
	UFUNCTION(BlueprintCallable)
	virtual int32 GetVal();

};
