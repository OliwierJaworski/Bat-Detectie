// Auto generated code by esphome
// ========== AUTO GENERATED INCLUDE BLOCK BEGIN ===========
#include "esphome.h"
using namespace esphome;
using std::isnan;
using std::min;
using std::max;
using namespace sensor;
logger::Logger *logger_logger_id;
web_server_base::WebServerBase *web_server_base_webserverbase_id;
captive_portal::CaptivePortal *captive_portal_captiveportal_id;
wifi::WiFiComponent *wifi_wificomponent_id;
mdns::MDNSComponent *mdns_mdnscomponent_id;
esphome::ESPHomeOTAComponent *esphome_esphomeotacomponent_id;
safe_mode::SafeModeComponent *safe_mode_safemodecomponent_id;
api::APIServer *api_apiserver_id;
using namespace api;
StartupTrigger *startuptrigger_id;
Automation<> *automation_id;
DelayAction<> *delayaction_id;
using namespace i2c;
i2c::ArduinoI2CBus *i2c_arduinoi2cbus_id;
preferences::IntervalSyncer *preferences_intervalsyncer_id;
sht3xd::SHT3XDComponent *sht3xd_sht3xdcomponent_id;
sensor::Sensor *sensor_sensor_id;
sensor::Sensor *sensor_sensor_id_2;
deep_sleep::DeepSleepComponent *deep_sleep_ctrl;
deep_sleep::EnterDeepSleepAction<> *deep_sleep_enterdeepsleepaction_id;
#define yield() esphome::yield()
#define millis() esphome::millis()
#define micros() esphome::micros()
#define delay(x) esphome::delay(x)
#define delayMicroseconds(x) esphome::delayMicroseconds(x)
// ========== AUTO GENERATED INCLUDE BLOCK END ==========="

void setup() {
  // ========== AUTO GENERATED CODE BEGIN ===========
  // async_tcp:
  //   {}
  // esphome:
  //   name: envsensor33
  //   friendly_name: envsensor33
  //   on_boot:
  //   - priority: -10.0
  //     then:
  //     - delay: 15s
  //       type_id: delayaction_id
  //     - deep_sleep.enter:
  //         id: deep_sleep_ctrl
  //       type_id: deep_sleep_enterdeepsleepaction_id
  //     automation_id: automation_id
  //     trigger_id: startuptrigger_id
  //   build_path: build\envsensor33
  //   area: ''
  //   platformio_options: {}
  //   includes: []
  //   libraries: []
  //   name_add_mac_suffix: false
  //   min_version: 2024.6.5
  App.pre_setup("envsensor33", "envsensor33", "", "", __DATE__ ", " __TIME__, false);
  // sensor:
  // logger:
  //   id: logger_logger_id
  //   baud_rate: 115200
  //   tx_buffer_size: 512
  //   deassert_rts_dtr: false
  //   hardware_uart: USB_CDC
  //   level: DEBUG
  //   logs: {}
  logger_logger_id = new logger::Logger(115200, 512);
  logger_logger_id->set_uart_selection(logger::UART_SELECTION_USB_CDC);
  logger_logger_id->pre_setup();
  logger_logger_id->set_component_source("logger");
  App.register_component(logger_logger_id);
  // web_server_base:
  //   id: web_server_base_webserverbase_id
  web_server_base_webserverbase_id = new web_server_base::WebServerBase();
  web_server_base_webserverbase_id->set_component_source("web_server_base");
  App.register_component(web_server_base_webserverbase_id);
  // captive_portal:
  //   id: captive_portal_captiveportal_id
  //   web_server_base_id: web_server_base_webserverbase_id
  captive_portal_captiveportal_id = new captive_portal::CaptivePortal(web_server_base_webserverbase_id);
  captive_portal_captiveportal_id->set_component_source("captive_portal");
  App.register_component(captive_portal_captiveportal_id);
  // wifi:
  //   fast_connect: true
  //   id: wifi_wificomponent_id
  //   domain: .local
  //   reboot_timeout: 15min
  //   power_save_mode: LIGHT
  //   passive_scan: false
  //   enable_on_boot: true
  //   networks:
  //   - ssid: batSenseWifi
  //     password: batSenseWifi123-_-
  //     id: wifi_wifiap_id
  //     priority: 0.0
  //   use_address: envsensor33.local
  wifi_wificomponent_id = new wifi::WiFiComponent();
  wifi_wificomponent_id->set_use_address("envsensor33.local");
  {
  wifi::WiFiAP wifi_wifiap_id = wifi::WiFiAP();
  wifi_wifiap_id.set_ssid("batSenseWifi");
  wifi_wifiap_id.set_password("batSenseWifi123-_-");
  wifi_wifiap_id.set_priority(0.0f);
  wifi_wificomponent_id->add_sta(wifi_wifiap_id);
  }
  wifi_wificomponent_id->set_reboot_timeout(900000);
  wifi_wificomponent_id->set_power_save_mode(wifi::WIFI_POWER_SAVE_LIGHT);
  wifi_wificomponent_id->set_fast_connect(true);
  wifi_wificomponent_id->set_passive_scan(false);
  wifi_wificomponent_id->set_enable_on_boot(true);
  wifi_wificomponent_id->set_component_source("wifi");
  App.register_component(wifi_wificomponent_id);
  // mdns:
  //   id: mdns_mdnscomponent_id
  //   disabled: false
  //   services: []
  mdns_mdnscomponent_id = new mdns::MDNSComponent();
  mdns_mdnscomponent_id->set_component_source("mdns");
  App.register_component(mdns_mdnscomponent_id);
  // ota:
  // ota.esphome:
  //   platform: esphome
  //   password: '1'
  //   id: esphome_esphomeotacomponent_id
  //   version: 2
  //   port: 3232
  esphome_esphomeotacomponent_id = new esphome::ESPHomeOTAComponent();
  esphome_esphomeotacomponent_id->set_port(3232);
  esphome_esphomeotacomponent_id->set_auth_password("1");
  esphome_esphomeotacomponent_id->set_component_source("esphome.ota");
  App.register_component(esphome_esphomeotacomponent_id);
  // safe_mode:
  //   id: safe_mode_safemodecomponent_id
  //   boot_is_good_after: 1min
  //   disabled: false
  //   num_attempts: 10
  //   reboot_timeout: 5min
  safe_mode_safemodecomponent_id = new safe_mode::SafeModeComponent();
  safe_mode_safemodecomponent_id->set_component_source("safe_mode");
  App.register_component(safe_mode_safemodecomponent_id);
  if (safe_mode_safemodecomponent_id->should_enter_safe_mode(10, 300000, 60000)) return;
  // api:
  //   password: '1'
  //   id: api_apiserver_id
  //   port: 6053
  //   reboot_timeout: 15min
  api_apiserver_id = new api::APIServer();
  api_apiserver_id->set_component_source("api");
  App.register_component(api_apiserver_id);
  api_apiserver_id->set_port(6053);
  api_apiserver_id->set_password("1");
  api_apiserver_id->set_reboot_timeout(900000);
  startuptrigger_id = new StartupTrigger(-10.0f);
  startuptrigger_id->set_component_source("esphome.coroutine");
  App.register_component(startuptrigger_id);
  automation_id = new Automation<>(startuptrigger_id);
  delayaction_id = new DelayAction<>();
  delayaction_id->set_component_source("esphome.coroutine");
  App.register_component(delayaction_id);
  delayaction_id->set_delay(15000);
  // i2c:
  //   sda: 33
  //   scl: 35
  //   scan: true
  //   id: i2c_arduinoi2cbus_id
  //   frequency: 50000.0
  i2c_arduinoi2cbus_id = new i2c::ArduinoI2CBus();
  i2c_arduinoi2cbus_id->set_component_source("i2c");
  App.register_component(i2c_arduinoi2cbus_id);
  i2c_arduinoi2cbus_id->set_sda_pin(33);
  i2c_arduinoi2cbus_id->set_scl_pin(35);
  i2c_arduinoi2cbus_id->set_frequency(50000);
  i2c_arduinoi2cbus_id->set_scan(true);
  // esp32:
  //   board: lolin_s2_mini
  //   framework:
  //     version: 2.0.5
  //     source: ~3.20005.0
  //     platform_version: platformio/espressif32@5.4.0
  //     type: arduino
  //   flash_size: 4MB
  //   variant: ESP32S2
  // preferences:
  //   id: preferences_intervalsyncer_id
  //   flash_write_interval: 60s
  preferences_intervalsyncer_id = new preferences::IntervalSyncer();
  preferences_intervalsyncer_id->set_write_interval(60000);
  preferences_intervalsyncer_id->set_component_source("preferences");
  App.register_component(preferences_intervalsyncer_id);
  // sensor.sht3xd:
  //   platform: sht3xd
  //   temperature:
  //     name: envsensor17 Temperature
  //     disabled_by_default: false
  //     id: sensor_sensor_id
  //     force_update: false
  //     unit_of_measurement: °C
  //     accuracy_decimals: 1
  //     device_class: temperature
  //     state_class: measurement
  //   humidity:
  //     name: envsensor17 Humidity
  //     disabled_by_default: false
  //     id: sensor_sensor_id_2
  //     force_update: false
  //     unit_of_measurement: '%'
  //     accuracy_decimals: 1
  //     device_class: humidity
  //     state_class: measurement
  //   address: 0x44
  //   update_interval: 10s
  //   id: sht3xd_sht3xdcomponent_id
  //   heater_enabled: false
  //   i2c_id: i2c_arduinoi2cbus_id
  sht3xd_sht3xdcomponent_id = new sht3xd::SHT3XDComponent();
  sht3xd_sht3xdcomponent_id->set_update_interval(10000);
  sht3xd_sht3xdcomponent_id->set_component_source("sht3xd.sensor");
  App.register_component(sht3xd_sht3xdcomponent_id);
  sht3xd_sht3xdcomponent_id->set_i2c_bus(i2c_arduinoi2cbus_id);
  sht3xd_sht3xdcomponent_id->set_i2c_address(0x44);
  sht3xd_sht3xdcomponent_id->set_heater_enabled(false);
  sensor_sensor_id = new sensor::Sensor();
  App.register_sensor(sensor_sensor_id);
  sensor_sensor_id->set_name("envsensor17 Temperature");
  sensor_sensor_id->set_object_id("envsensor17_temperature");
  sensor_sensor_id->set_disabled_by_default(false);
  sensor_sensor_id->set_device_class("temperature");
  sensor_sensor_id->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  sensor_sensor_id->set_unit_of_measurement("\302\260C");
  sensor_sensor_id->set_accuracy_decimals(1);
  sensor_sensor_id->set_force_update(false);
  sht3xd_sht3xdcomponent_id->set_temperature_sensor(sensor_sensor_id);
  sensor_sensor_id_2 = new sensor::Sensor();
  App.register_sensor(sensor_sensor_id_2);
  sensor_sensor_id_2->set_name("envsensor17 Humidity");
  sensor_sensor_id_2->set_object_id("envsensor17_humidity");
  sensor_sensor_id_2->set_disabled_by_default(false);
  sensor_sensor_id_2->set_device_class("humidity");
  sensor_sensor_id_2->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  sensor_sensor_id_2->set_unit_of_measurement("%");
  sensor_sensor_id_2->set_accuracy_decimals(1);
  sensor_sensor_id_2->set_force_update(false);
  sht3xd_sht3xdcomponent_id->set_humidity_sensor(sensor_sensor_id_2);
  // deep_sleep:
  //   id: deep_sleep_ctrl
  //   sleep_duration: 5min
  deep_sleep_ctrl = new deep_sleep::DeepSleepComponent();
  deep_sleep_ctrl->set_component_source("deep_sleep");
  App.register_component(deep_sleep_ctrl);
  deep_sleep_ctrl->set_sleep_duration(300000);
  // socket:
  //   implementation: bsd_sockets
  // network:
  //   enable_ipv6: false
  //   min_ipv6_addr_count: 0
  deep_sleep_enterdeepsleepaction_id = new deep_sleep::EnterDeepSleepAction<>(deep_sleep_ctrl);
  automation_id->add_actions({delayaction_id, deep_sleep_enterdeepsleepaction_id});
  // =========== AUTO GENERATED CODE END ============
  App.setup();
}

void loop() {
  App.loop();
}
