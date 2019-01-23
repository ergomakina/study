int reset, button1, button2, button3, button4 = 0;
int state = 0;

void setup()
{
    // User 1
    pinMode(8, OUTPUT);
    pinMode(12, INPUT);
    // User 2
    pinMode(7, OUTPUT);
    pinMode(11, INPUT);
    // User 3
    pinMode(6, OUTPUT);
    pinMode(10, INPUT);
    // User 4
    pinMode(5, OUTPUT);
    pinMode(9, INPUT);
    // RESET
    pinMode(13, INPUT);
}

void loop()
{
    reset = digitalRead(13);
    button1 = digitalRead(12);
    button2 = digitalRead(11);
    button3 = digitalRead(10);
    button4 = digitalRead(9);

    if (state == HIGH)
    {
        break;
    }

    if (reset == HIGH)
    {
        // ALL LED OFF
        digitalWrite(8, LOW);
        digitalWrite(7, LOW);
        digitalWrite(6, LOW);
        digitalWrite(5, LOW);
    }
    if (button1 == HIGH)
    {
        digitalWrite(8, HIGH);
    }
    if (button2 == HIGH)
    {
        digitalWrite(7, HIGH);
    }
    if (button3 == HIGH)
    {
        digitalWrite(6, HIGH);
    }
    if (button4 == HIGH)
    {
        digitalWrite(5, HIGH);
    }
}