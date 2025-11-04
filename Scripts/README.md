Deze map bevat de configuratie- en scriptbestanden die worden gebruikt voor het uitlezen van sensoren binnen het **Bat Detectie**-project.  

---

## Bestanden

### 1. `HTSensor.yaml`
**Onderwerp:** Configuratie van de SHT3X-sensor voor ESPHome.  
**Inhoud:**  
- Definieert de sensor (temperatuur en luchtvochtigheid) voor de S2 Mini.  
- Bevat instellingen zoals:
  - I²C-communicatiepinnen (`SDA`, `SCL`)
  - Update-interval voor sensormetingen
  - Logging en API-configuratie
  - Deep-sleep functionaliteit voor energiebeheer
- Wordt gebruikt in combinatie met ESPHome om firmware te genereren en te flashen naar de S2 Mini.
