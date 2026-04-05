// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StuctExample.generated.h"

USTRUCT(BlueprintType)
struct FStructExample
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "StructExample")
	float Radius;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "StructExample")
	float Timer;
};
