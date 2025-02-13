#define TRIG_PIN 12
#define ECHO_PIN 13

#define RED_PIN 4
#define GREEN_PIN 2
#define BLUE_PIN 15

#define BUZZER_PIN 17

void setup() {
    Serial.begin(115200);
    
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
    
    pinMode(BUZZER_PIN, OUTPUT);
}

long getDistance() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH);
    long distance = duration * 0.034 / 2;  // Convert to cm
    return distance;
}

void setColor(int r, int g, int b) {
    analogWrite(RED_PIN, r);
    analogWrite(GREEN_PIN, g);
    analogWrite(BLUE_PIN, b);
}

void beep(int frequency, int duration, int pause) {
    tone(BUZZER_PIN, frequency);
    delay(duration);
    noTone(BUZZER_PIN);
    delay(pause);
}

void loop() {
    long distance = getDistance();
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance < 5) {  // 🔴 AAAAAAA!
        setColor(255, 0, 0);  // RED
        tone(BUZZER_PIN, 1000);  // Long Beep
    } 
    else if (distance >= 5 && distance < 10) {  // 🔴 Very Close
        setColor(255, 0, 0);
        beep(1000, 250, 150);
    } 
    else if (distance >= 10 && distance < 20) {  // 🟠 Medium Close
        setColor(255, 165, 0);  // Orange
        beep(800, 300, 200);
    } 
    else if (distance >= 20 && distance < 30) {  // 🟡 Near
        setColor(255, 255, 0);  // Yellow
        beep(600, 350, 300);
    } 
    else if (distance >= 30 && distance < 50) {  // 🟢 Far
        setColor(0, 255, 0);  // Green
        beep(400, 400, 400);
    } 
    else {  // Safe distance
        setColor(0, 255, 0);  // Green
    }

    delay(200);
}
