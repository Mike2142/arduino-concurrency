// Даём пинам понятные имена
constexpr int LED_RED_PIN = 2;
constexpr int LED_GREEN_PIN = 3;
constexpr int LED_YELLOW_PIN = 4;

// Переменные для счётчиков красного и зелёного светодиода
long millisLastRed = 0;
long millisLastGreen = 0;
long millisLastYellow = 0;
 
// Переменные для хранения состояний светодиодов
bool ledRedState = false;
bool ledGreenState = false;
bool ledYellowState = false;
 
void setup() {
  // Настраиваем пины со светодиодами в режим выхода
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_YELLOW_PIN, OUTPUT);
}
 
void loop() {
  // Засекаем текущее время
  long millisNow = millis();
  if (millisNow - millisLastRed > 100) {
    // Если интервал красного LED превысил 100 мс
    // Инвертируем его состояние
    millisLastRed = millisNow;
    ledRedState = !ledRedState;
    digitalWrite(LED_RED_PIN, ledRedState);
  }
  if (millisNow - millisLastGreen > 1000) {
    // Если интервал зелёного LED превысил 1000 мс
    // Инвертируем его состояние
    millisLastGreen = millisNow;
    ledGreenState = !ledGreenState;
    digitalWrite(LED_GREEN_PIN, ledGreenState);
  }

  if (millisNow - millisLastYellow > 2000) {
    // Если интервал желтого LED превысил 2000 мс
    // Инвертируем его состояние
    millisLastYellow = millisNow;
    ledYellowState = !ledYellowState;
    digitalWrite(LED_YELLOW_PIN, ledYellowState);
  }
}