#define RESET_SW 4
#define NUSERS 4

const char sw[NUSERS] = {12, 11, 10, 9};
const char led[NUSERS] = {8, 7, 6, 5};

void setup()
{
  int i;
  pinMode(RESET_SW, INPUT);
  for (i = 0; i < NUSERS; i++) {
    pinMode(sw[i], INPUT);
    pinMode(led[i], OUTPUT);
    digitalWrite(led[i], LOW);
  }
}

static char paused = 0;
static char user = 0;

void loop()
{
  if (paused) {
    if (digitalRead(RESET_SW) == LOW) {
      digitalWrite(led[user], LOW);
      paused = 0;
    }
    else return;
  }
  else {
    if (digitalRead(sw[user]) == LOW) {
      paused = 1;
      digitalWrite(led[user], HIGH);
      return;
    }
  }
  user = (user + 1) % NUSERS;
}