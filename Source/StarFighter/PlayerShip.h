// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Cola.h"
#include "Nave.h"
#include "PlayerShip.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API APlayerShip : public ANave
{
	GENERATED_BODY()

	// creando cola para almacenar misiles
	Cola<class AMissile*> ColaMissiles;

public:
	APlayerShip();

	// propiedades propias de la nave jugador
	UPROPERTY(BlueprintReadOnly)
		float Max_Health;  // salud maxima
	UPROPERTY(BlueprintReadOnly)
		float Current_Health; // salud actual
	UPROPERTY(BlueprintReadOnly)
		float Max_Armor; // armadura maxima
	UPROPERTY(BlueprintReadOnly)
		float Current_Armor; // armadura actual

	// tama�o del campo de juego
	UPROPERTY(EditAnywhere)
		float Field_Width; // ancho del campo
	UPROPERTY(EditAnywhere)
		float Field_Height; // altura del campo

	// propiedad para saber la puntuacion del jugador
	UPROPERTY(BlueprintReadOnly)
		float PlayerScore;

	// propiedad velocidad maxima de la nave jugador
	UPROPERTY(EditAnywhere)
		float MaxVelocity;

	/** Offset from the ships location to spawn projectiles */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		FVector GunOffset;

	// variable para saber que tan rapido dispara el arma
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float FireRate;
	// sonido del disparo
	UPROPERTY(Category = Audio, EditAnywhere, BlueprintReadWrite)
		class USoundBase* FireSound;
	
	// Nombres est�ticos para enlaces de ejes y disparo
	static const FName MoveHorizontalBinding;
	static const FName MoveVerticalBinding;
	static const FName FireBinding1;
	static const FName FireBinding2;
	static const FName FireBinding3;
	static const FName FireBinding4;

	// variables tipo vector para la nave jugador
	FVector Current_Location; // para la ubicacion actual
	FVector New_Location; // para la nueva ubicacion

	// metodos para el disparo de las 4 municiones diferentes
	void Fire1();
	void Fire2();
	void Fire3();
	void Fire4();
	void FireWeapon1(FVector FireDirection);
	void FireWeapon2(FVector FireDirection);
	void FireWeapon3(FVector FireDirection);
	void FireWeapon4(FVector FireDirection);
	void ShotTimerExpired(); // manejador del temporizador del disparo

	// metodos para el movimiento de la nave jugador
	void MoveHorizontal(float AxisValue);
	void MoveVertical(float AxisValue);

protected:
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:

	// bandera para controlar los disparos
	uint32 bCanFire : 1;

	// Variable para una gesti�n eficiente del temporizador ShotTimerExpired
	FTimerHandle TimerHandle_ShotTimerExpired; 

};
