// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseEnum.generated.h"

UENUM(Blueprintable)
enum class EBaseEnum : uint8
{
	None UMETA(DisplayName = "None"),
	Enum1 UMETA(DisplayName = "Enum1"),
	Enum2 UMETA(DisplayName = "Enum2")
};
