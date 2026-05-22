# Monster Spawner (raylib)

Kleine referentie-oplossing voor de opdracht:

- Alle gameplay-code staat in `namespace game`.
- `MonsterStats` bevat `speed` en `power`.
- `Monster` laadt een texture in de constructor en ruimt op in de destructor.
- In `main` wordt met `S` een nieuw monster (`new`) toegevoegd aan `std::vector<Monster*>`.

## Bestanden

- `main.cpp`: game loop + spawnen met `KEY_S`
- `Monster.h`: `MonsterStats` + `Monster` declaratie
- `Monster.cpp`: constructor/destructor/update/draw implementatie

## Bouwen en starten

```powershell
cmake -S . -B cmake-build-debug
cmake --build cmake-build-debug
.\cmake-build-debug\oef1\oef1.exe
```

## Controls

- `S`: spawn nieuw monster
- `ESC`: afsluiten

