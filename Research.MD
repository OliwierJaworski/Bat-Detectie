# S2 Mini & PowerBoost 500 Charger

Dit project combineert de **S2 Mini** microcontroller met de **Adafruit PowerBoost 500 Charger** voor een compacte, draagbare oplossing die zowel voeding als opladen ondersteunt.

## Componenten

- **S2 Mini**
  - ESP32-S2 gebaseerde microcontroller
  - Ondersteunt Wi-Fi
  - Klein formaat en laag energieverbruik

- **PowerBoost 500 Charger**
  - LiPo/Li-ion batterij lader
  - 5V boost converter tot max. 500mA
  - Micro-USB aansluiting voor opladen
  - Automatische overschakeling tussen USB- en batterijvoeding

## Functionaliteit

- Voeding van de **S2 Mini** via een LiPo- of Li-ion batterij.
- Opladen van de batterij via micro-USB.
- 5V output van de PowerBoost voedt direct de S2 Mini.
- Ideaal voor draagbare IoT-projecten.

## Aansluitingen

1. **Batterij → PowerBoost**
   - Verbind een LiPo/Li-ion batterij met de JST-connector van de PowerBoost.

2. **PowerBoost → S2 Mini**
   - Sluit de **5V-uitgang** van de PowerBoost aan op de **5V/VBUS pin** van de S2 Mini.
   - Sluit **GND** van beide borden aan.

3. **Opladen**
   - Gebruik een micro-USB kabel op de PowerBoost om de batterij op te laden.
   - Het systeem kan tijdens het opladen blijven functioneren.

## Let op

- Zorg dat de aangesloten batterij correct gepolariseerd is (rode draad = +, zwarte draad = -).
- De PowerBoost levert max. 500mA; houd rekening met stroomverbruik van de S2 Mini en randapparatuur.
- Gebruik een geschikte LiPo- of Li-ion batterij (bij voorkeur ≥ 500mAh).

## Toepassingen

- Draagbare IoT-projecten
- Sensoren en datalogging
- Kleine robotica toepassingen
- Wearables

## Referenties

- [S2 Mini documentatie](https://www.wemos.cc/en/latest/s2/s2_mini.html)  
- [Adafruit PowerBoost 500 Charger](https://learn.adafruit.com/adafruit-powerboost-500-charger)
