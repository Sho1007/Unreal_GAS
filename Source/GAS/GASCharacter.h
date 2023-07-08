// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"

#include <GameplayTagContainer.h>
#include <GameplayEffectTypes.h>
#include <AbilitySystemInterface.h>

#include "GASCharacter.generated.h"


UCLASS(config=Game)
class AGASCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities, meta = (AllowPrivateAccess = "true"))
	class UAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
	class URuneAttributeSet* Attributes;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

public:
	AGASCharacter();
	

protected:
	// To add mapping context
	virtual void BeginPlay();

public:
	

	// Inherited via IAbilitySystemInterface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = Abilities)
	TSubclassOf<class UGameplayEffect> DefaultAttributeEffect;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = Abilities)
	TArray<TSubclassOf<class UGameplayAbility>> DefaultAbilities;

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	virtual void InitializeAttributes();
	virtual void GiveDefaultAbilities();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Attributes, Meta = (AllowPrivateAccess = true))
	float MaxHealth = 100;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Attributes, Meta = (AllowPrivateAccess = true))
	float MaxStemina = 100;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Attributes, Meta = (AllowPrivateAccess = true))
	float MaxEnergy = 100;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Attributes, Meta = (AllowPrivateAccess = true))
	float MaxHidration = 100;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Attributes, Meta = (AllowPrivateAccess = true))
	float MaxStat = 99;


	// Wait for Remove

//public:
//	/** MappingContext */
//	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
//	class UInputMappingContext* DefaultMappingContext;

	//public:
	///** Camera boom positioning the camera behind the character */
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	//class USpringArmComponent* CameraBoom;

	///** Follow camera */
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	//class UCameraComponent* FollowCamera;

	//protected:
	//// APawn interface
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
//	/** Called for movement input */
//	void Move(const FInputActionValue& Value);
//
//	/** Called for looking input */
//	void Look(const FInputActionValue& Value);
//public:
	///** Returns CameraBoom subobject **/
	//FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	///** Returns FollowCamera subobject **/
	//FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

