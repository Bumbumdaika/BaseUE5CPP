// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ExampleStructure.generated.h"

USTRUCT(BlueprintType)
struct FExampleStruct
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "StructExample")
	float Radius;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "StructExample")
	float Timer;
};