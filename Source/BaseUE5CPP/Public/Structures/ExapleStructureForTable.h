// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ExapleStructureForTable.generated.h"

USTRUCT(BlueprintType)
struct FExapleStructureForTable : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "StructExample")
	float Radius;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "StructExample")
	float Timer;
};
