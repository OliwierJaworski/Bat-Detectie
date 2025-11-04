# Flashen van de S2 Mini met ESPHome

## Overzicht
In dit onderdeel van het project hebben we de **S2 Mini** geconfigureerd en geflasht met behulp van **ESPHome**.  
Het doel was om de microcontroller correct te programmeren zodat deze de SHT3X-sensor kon uitlezen en de data kon doorsturen via Wi-Fi.  
Tijdens dit proces kreeg ik ondersteuning van mijn junior collega **Alexander Petry**, die mee heeft geholpen bij het opstellen van de benodigde configuratiebestanden en het flashproces.

## Installatie van ESPHome
Om te beginnen moest **ESPHome** lokaal worden geïnstalleerd op de computer.  
Dit gebeurde via de **Command Prompt (CMD)** of **PowerShell** met het volgende commando:

```bash
pip install esphome
```

Na de installatie werd gecontroleerd of ESPHome correct was geïnstalleerd door het versienummer op te vragen:

```bash
esphome version
```

Wanneer de versie correct werd weergegeven, was de installatie geslaagd en kon worden begonnen met het flashen van de S2 Mini.

## Flashen van de S2 Mini
De S2 Mini werd via USB verbonden met de computer.  
Vervolgens werd met behulp van het commando hieronder het YAML-configuratiebestand uitgevoerd en geflasht naar het board:

```bash
esphome run .\HTSensor.yaml
```

Hierbij werd de firmware automatisch gegenereerd, gecompileerd en overgezet naar de S2 Mini.  
Na het succesvol flashen kon de microcontroller onmiddellijk worden getest door de **logfunctie** van ESPHome te gebruiken:

```bash
esphome logs .\HTSensor.yaml
```

Via deze logs konden we controleren of de sensor succesvol data doorgaf en of de verbinding met Wi-Fi tot stand kwam.

## YAML-configuratiebestand
Samen met Alexander werd het volgende **YAML-bestand** opgesteld voor de S2 Mini.  
Het bestand bevat de configuratie voor de Wi-Fi-verbinding, de sensor, logging, en de automatische deep-sleep functionaliteit om energie te besparen.

```yaml
esphome:
  name: envsensor17 #nummer van het doosje
  friendly_name: envsensor17
  on_boot:
    priority: -10
    then:
      - delay: 15s  # geef Wi-Fi en sensor tijd om te initialiseren voor slaapstand
      - deep_sleep.enter: deep_sleep_ctrl

esp32:
  board: lolin_s2_mini
  framework:
    type: arduino

logger:

api:
  password: "1"

ota:
  - platform: esphome
    password: "1"

wifi:
  ssid: "batSenseWifi"
  password: "batSenseWifi123-_-"
  fast_connect: true   # versnelt herverbinding voor vaste Wi-Fi

captive_portal:

i2c:
  sda: 33
  scl: 35
  scan: true

sensor:
  - platform: sht3xd
    temperature:
      name: "envsensor17 Temperature"
    humidity:
      name: "envsensor17 Humidity"
    address: 0x44
    update_interval: 10s

deep_sleep:
  id: deep_sleep_ctrl
  sleep_duration: 5min
```

## Observaties
- Het flashproces verliep **vlot en zonder fouten**.  
- Na het opstarten van de S2 Mini konden de waarden van **temperatuur** en **luchtvochtigheid** correct worden uitgelezen.  
- De deep-sleep functionaliteit werkte zoals verwacht, wat essentieel is voor energie-efficiëntie bij langdurig gebruik in het veld.  
- De Wi-Fi-verbinding met het netwerk *batSenseWifi* werd stabiel opgezet en bleef behouden tijdens de testperiode.

## Resultaat
- De **S2 Mini** is succesvol geflasht met een volledig functionele ESPHome-configuratie.  
- De sensor communiceert betrouwbaar via I²C en Wi-Fi.  
- Deze configuratie zal dienen als **basisfirmware** voor de verdere uitrol van de omgevingssensoren binnen het project.
