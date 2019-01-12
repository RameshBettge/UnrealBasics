// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/CoreUObject/Public/UObject/NoExportTypes.h"
#include "Object.h"
#include "MyUObject.generated.h"


/**
 * 
 */
#pragma once

UCLASS()
class LEARNING_BASICS_API UMyUObject : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
		int32 TestInt = 0;
};
