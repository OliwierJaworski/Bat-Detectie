# Onderzoeksproject: Vleermuizen en Spouwmuren

<img width="2480" height="1642" alt="image" src="https://github.com/BjarniHeselmans/Bat-Detectie/blob/main/Docs/Attachments/ProjectPicture.png" />

Dit project beschrijft een embedded sensormodule voor het monitoren van
vleermuisactiviteit en omgevingscondities in spouwmuren, opgebouwd rond een
ESP32-S2 (S2 Mini), een SHT30 temperatuurs- en vochtigheidssensor en een
batterijvoedingsmodule met draadloze datadoorsturing via ESPHome.

---

## Inleiding

Dit project kadert binnen de opleiding Elektronica-ICT aan Hogeschool PXL en
sluit aan bij een breder onderzoeksopzet rond monitoring, IoT en ecologie.  
De sensormodules worden ingezet om het gebruik van spouwmuren door vleermuizen
te bestuderen aan de hand van omgevingsmetingen en beweging, met als doel
zowel **ecologische inzichten** als **praktische richtlijnen** voor
bouwkundige toepassingen te verzamelen.

---

## Doelstelling

Het doel is om een compacte, draagbare hardwaremodule te ontwikkelen die
temperatuur en luchtvochtigheid in spouwmuren betrouwbaar meet en de gegevens
draadloos doorstuurt naar een overkoepelend systeem.  

De module moet:
- autonoom op batterij kunnen werken;
- reproduceerbaar zijn op basis van de documentatie;
- via ESPHome alle sensoren koppelen en de meetdata via Wi‑Fi doorsturen;
- meetdata beschikbaar maken in een hoger niveau platform
  (zoals Home Assistant of een dataloggingomgeving).

---

## Materialen en Methoden

### Hardware

De hardware bestaat uit:
- S2 Mini (ESP32-S2 met Wi‑Fi);
- PowerBoost 500 Charger voor batterijvoeding en laadfunctie;
- SHT30/SHT3X sensor voor temperatuur- en vochtigheidsmeting.

De bekabeling en opstelling zijn beschreven in `Docs/Research.md`.

### Firmware en datadoorsturing

De firmware wordt gerealiseerd met **ESPHome** op basis van:
- `Scripts/HTSensor.yaml`

ESPHome wordt gebruikt als centrale laag om alle sensoren aan de ESP32-S2 te
koppelen en de ruwe meetwaarden te vertalen naar entiteiten die via Wi‑Fi
beschikbaar zijn op het netwerk.  
In de ESPHome-configuratie worden de sensoren (zoals de SHT3X) gedefinieerd,
worden meetintervallen ingesteld, wordt deep‑sleep geconfigureerd voor
energiebesparing en wordt gespecificeerd naar welke host (bijvoorbeeld
Home Assistant) de data wordt doorgestuurd.  

Samengevat:
- ESPHome koppelt elke sensor logisch aan de microcontroller;
- de ESP32-S2 stuurt de meetdata via Wi‑Fi naar het netwerk;
- een extern systeem kan de data vervolgens loggen, verwerken en visualiseren.

---

## Projectstructuur

Docs/
Research.md
01_board_controle.md
02_sensor_kabels.md
03_s2mini_flashen.md
Attachments/
... (screenshots en foto’s)

Scripts/
HTSensor.yaml


- `Docs/` bevat alle documentatie rond hardware, tests en opbouw.  
- `Scripts/` bevat de ESPHome-configuratiebestanden waarmee de sensoren worden
  gekoppeld en de datadoorsturing via Wi‑Fi wordt geregeld.

---

## Installatie en Gebruik

1. **Hardware opzetten**  
   Volg `Docs/Research.md` voor het aansluiten van:
   - S2 Mini  
   - PowerBoost  
   - SHT30/SHT3X sensor

2. **ESPHome configureren en firmware flashen**  
   - Installeer ESPHome op je systeem.  
   - Plaats `HTSensor.yaml` in je ESPHome-projectmap.  
   - Flash de firmware naar de S2 Mini:
     ```
     esphome run HTSensor.yaml
     ```
   In deze configuratie worden alle sensoren gekoppeld en wordt Wi‑Fi ingesteld
   zodat de module verbinding maakt met je netwerk.

3. **Testen en logs bekijken**  

esphome logs HTSensor.yaml

Hiermee kun je in realtime de sensorwaarden bekijken en controleren:
- of de SHT30/SHT3X correct uitgelezen wordt;
- of de Wi‑Fi-verbinding tot stand komt;
- of de entiteiten zichtbaar zijn in het gekoppelde systeem
  (bijvoorbeeld Home Assistant).

---

## Resultaten

Met de opgeleverde module kan in spouwmuren een stabiele meting van temperatuur
en luchtvochtigheid uitgevoerd worden, waarbij ESPHome alle sensoren beheert en
de data via Wi‑Fi beschikbaar maakt als entiteiten in het netwerk.  
De combinatie van documentatie in `Docs/` en configuratie in `Scripts/`
maakt het mogelijk om de opstelling te reproduceren, het gedrag van de module
te testen en de meetresultaten te koppelen aan het bredere vleermuisonderzoek.

---

## Conclusie

De combinatie van S2 Mini, PowerBoost, SHT30 en ESPHome levert een praktische
embedded oplossing voor omgevingsmonitoring in spouwmuren, met een duidelijke
scheiding tussen hardware, firmwareconfiguratie en documentatie.  
ESPHome vereenvoudigt het koppelen van sensoren en de Wi‑Fi‑datadoorsturing,
waardoor de focus kan liggen op metingen, analyse en de ecologische en
bouwkundige relevantie van het project.
