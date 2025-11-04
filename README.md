# Onderzoeksproject: Vleermuizen en Spouwmuren
<img width="2480" height="1642" alt="image" src="https://github.com/user-attachments/assets/67e67353-f503-4871-95e1-b014d2f404eb" />

## Introductie
Dit project onderzoekt hoe vleermuizen spouwmuren gebruiken als leef- en verplaatsingsruimte.  
We ontwikkelen sensormodules die temperatuur, luchtvochtigheid en beweging kunnen registreren.  
Het doel is om zowel **ecologische inzichten** te verkrijgen voor de bescherming van vleermuissoorten als **bouwkundige richtlijnen** te ontwikkelen voor renovatie en isolatie.

---

## Doel van het onderzoek
- In kaart brengen hoe vleermuizen spouwmuren benutten.  
- Begrijpen welke bouwkundige factoren (breedte, hoogte, openingen) hun beweging beïnvloeden.  

---

## Belang van het onderzoek
- **Ecologisch:** Bescherming van vleermuissoorten door beter inzicht in hun gedrag.  
- **Bouwkundig:** Bieden van richtlijnen om diervriendelijke renovatie en isolatie te ondersteunen.  

---

## Aanpak
Het onderzoek wordt uitgevoerd met behulp van:  
- Observaties met warmtecamera’s.  
- Akoestische detectie.  
- Ontwikkeling van compacte, draagbare sensormodules.  

---

## Terugblik vorig jaar
In een eerdere projectfase zijn de eerste sensormodules gebouwd.  
Daarbij kwamen enkele uitdagingen naar voren:  
- Beperkte batterijduur.  
- Problemen door vocht en condensatie.  
- Beperkingen in draadloze communicatie.  

---

## Hardwareoplossing
Om deze problemen aan te pakken, werken we met een nieuwe combinatie van componenten:  
- **[S2 Mini](https://github.com/BjarniHeselmans/Bat-Detectie/blob/main/Docs/Attachments/esp32-s2-mini.jpg)** (ESP32-S2 microcontroller met Wi-Fi).  
- **[PowerBoost 500 Charger](https://github.com/BjarniHeselmans/Bat-Detectie/blob/main/Docs/Attachments/Power-Boost-5000.jpg)** (voor batterijvoeding en opladen).  
- **[SHT30 sensor](https://github.com/BjarniHeselmans/Bat-Detectie/blob/main/Docs/Attachments/SHT30.jpg)** (voor temperatuur- en luchtvochtigheidsmetingen).
- [Deze set-up](https://github.com/BjarniHeselmans/Bat-Detectie/blob/main/Docs/Research.md)
 maakt het mogelijk om betrouwbare metingen te doen in spouwmuren en data draadloos door te sturen.  

---

## Doelstellingen
### Must-haves
- Ontwikkelen en opleveren van de hardwaremodule.  
- Documenteren in een Application Note.  
- Documenteren in deze GitHub README (Markdown).  
- Code review en versiebeheer via GitHub.  

### Nice-to-have
- Ontwerp en productie van een PCB.  

---

## Toepassingen
- Onderzoek naar vleermuizen in spouwmuren.  
- Algemeen draagbare IoT-projecten.  
- Sensoren en datalogging.  
- Omgevingsmonitoring (temperatuur en luchtvochtigheid).  

---

## Projectstructuur

De projectbestanden zijn georganiseerd in twee hoofdmappen:

### 1. `Docs/`
Bevat alle documentatie met betrekking tot het project, inclusief:
- Hardwareonderzoek (`Research.md`)
- Boardtests (`01_board_controle.md`)
- Sensorbekabeling en aanpassingen (`02_sensor_kabels.md`)
- Flashen en configuratie van de S2 Mini met ESPHome (`03_s2mini_flashen.md`)

**Bijlagen:** screenshots en foto’s van de hardware in `Docs/Attachments/`.

### 2. `Scripts/`
Bevat de configuratiebestanden en scripts voor de sensoren:
- `HTSensor.yaml` – YAML-configuratie voor ESPHome waarmee de S2 Mini de SHT3X-sensor kan uitlezen, deep-sleep gebruiken en data via Wi-Fi verzenden.

---

## Installatie en gebruik

1. **Hardware opzetten:**  
   - Volg de instructies in `Docs/Research.md` voor het aansluiten van de S2 Mini, PowerBoost en SHT30/SHT3X sensor.

2. **Firmware flashen:**  
   - Gebruik de YAML-bestanden uit `Scripts/` in combinatie met ESPHome (`esphome run.\ HTSensor.yaml`) om de S2 Mini te programmeren.

3. **Testen en logs bekijken:**  
   - Via `esphome logs HTSensor.yaml` kun je realtime sensorwaarden bekijken en controleren of de communicatie werkt.

---
