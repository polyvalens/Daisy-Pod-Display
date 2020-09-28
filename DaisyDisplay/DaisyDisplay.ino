/*
 * Display for Daisy Pod 
 * Translate LED1 & LED2 states to text strings.
 * 
 * CPV, 28/09/2020
 */
 
#include <LiquidCrystal.h>

LiquidCrystal lcd(6,7,5,4,3,2);

uint8_t led1r_pin = 8;
uint8_t led1g_pin = 9;
uint8_t led1b_pin = 10;
uint8_t led2r_pin = 11;
uint8_t led2g_pin = 12;
uint8_t led2b_pin = 13;
uint8_t pot1_pin = A0;
uint8_t pot2_pin = A1;

// PB1 scrolls through this menu.
char *main_menu[] =
{
// 0123456789012345
  "Pollen(8)       ", // 0, off
  "Filter          ", // 1, red
  "Performance     ", // 2, green
  "EQ/External     ", // 3, yellow
  "Effects         ", // 4, blue
  "Modulation      ", // 5, purple
  "Mixer           ", // 6, cyan
  "Oscillators     ", // 7, white
};

// PB2, off
char *no_menu[] =
{
 //0123456789012345
  "                ", // 0, off 0
  "HammondEggsMusic", // 1, red 2
  "                ", // 2, green 5
  "                ", // 3, yellow 7
  "                ", // 4, blue 6
  "Daisy Pod       ", // 5, purple 4
  "on              ", // 6, cyan 3
  "by              ", // 7, white 1
};

// PB2, White
char *oscillator_menu[] =
{
 //0123456789012345
  "Tune coarse     ", // 0, off
  "Type            ", // 1, red
  "Sync/EG depth   ", // 2, green
  "PWM amount      ", // 3, yellow
  "Vibrato min     ", // 4, blue
  "Sub-shape       ", // 5, purple
  "Shape           ", // 6, cyan
  "Tune fine       ", // 7, white
};

// PB2, Red
char *filter_menu[] =
{
 //0123456789012345
  "Cutoff/Res      ", // 0, off
  "- (Model)       ", // 1, red
  "EG SR           ", // 2, green
  "Tracking        ", // 3, yellow
  "- (Mode)        ", // 4, blue
  "EG AD           ", // 5, purple
  "EG/LFO depth    ", // 6, cyan
  "Overdrive       ", // 7, white
};

// PB2, Cyan
char *mixer_menu[] =
{
 //0123456789012345
  "Osc1/2 level    ", // 0, off
  "Ext in level    ", // 1, red
  "EG SR           ", // 2, green
  "-               ", // 3, yellow
  "-               ", // 4, blue
  "EG AD           ", // 5, purple
  "-               ", // 6, cyan
  "Noise           ", // 7, white
};

// PB2, Purple
char *modulation_menu[] =
{
 //0123456789012345
  "LFO1/2 rate     ", // 0, off
  "-               ", // 1, red
  "EG SR pitch     ", // 2, green
  "-               ", // 3, yellow
  "-               ", // 4, blue
  "EG AD pitch     ", // 5, purple
  "-               ", // 6, cyan
  "-               ", // 7, white
};

// PB2, Green
char *performance_menu[] =
{
 //0123456789012345
  "Mode/Port R     ", // 0, off
  "Port T/Bend T   ", // 1, red
  "Arp dwll/rate   ", // 2, green
  "Detune          ", // 3, yellow
  "Bend range      ", // 4, blue
  "Arp mode/rate   ", // 5, purple
  "Modwheel        ", // 6, cyan
  "Port R/Unispr   ", // 7, white
};

// PB2, Blue
char *effects_menu[] =
{
 //0123456789012345
  "FX type         ", // 0, off
  "Delay/Rev       ", // 1, red
  "-               ", // 2, green
  "Rev DW/FB       ", // 3, yellow
  "Dry/Wet         ", // 4, blue
  "-               ", // 5, purple
  "Delay rate/FB   ", // 6, cyan
  "FX rate/depth   ", // 7, white
};

// PB2, Yellow
char *eq_misc_menu[] =
{
 //0123456789012345
  "Level lo/hi     ", // 0, off
  "Freq lo/hi      ", // 1, red
  "-               ", // 2, green
  "-               ", // 3, yellow
  "-               ", // 4, blue
  "Click level     ", // 5, purple
  "Ext in/Rout     ", // 6, cyan
  "Level mid/En    ", // 7, white
};

char **led2_menus[] =
{
  no_menu, // off
  filter_menu, // red
  performance_menu, // green
  eq_misc_menu, // yellow
  effects_menu, // blue
  modulation_menu, // purple
  mixer_menu, // cyan
  oscillator_menu, // white
};

char *string_table[] =
{
 //0123456789012345
  "off             ", // 0
  "red             ", // 1
  "green           ", // 2
  "yellow          ", // 3
  "blue            ", // 4
  "purple          ", // 5
  "cyan            ", // 6
  "white           ", // 7
};

void setup(void)
{
  lcd.begin(16,2);
  lcd.print("- DaisyDisplay -");
  pinMode(led1r_pin,INPUT);
  pinMode(led1g_pin,INPUT);
  pinMode(led1b_pin,INPUT);
  pinMode(led2r_pin,INPUT);
  pinMode(led2g_pin,INPUT);
  pinMode(led2b_pin,INPUT);
}

void loop(void)
{
  uint8_t led1 = 0;
  uint8_t led2 = 0;
  // 0 to 99%.
  int pot1 = 152.0*(float)analogRead(pot1_pin)/1024.0; // 3V3 to 5V
  int pot2 = 152.0*(float)analogRead(pot2_pin)/1024.0; // 3V3 to 5V
  if (digitalRead(led1r_pin)==0) led1 |= 0x01;
  if (digitalRead(led1g_pin)==0) led1 |= 0x02;
  if (digitalRead(led1b_pin)==0) led1 |= 0x04;
  if (digitalRead(led2r_pin)==0) led2 |= 0x01;
  if (digitalRead(led2g_pin)==0) led2 |= 0x02;
  if (digitalRead(led2b_pin)==0) led2 |= 0x04;
  lcd.setCursor(0,0);
  lcd.print(main_menu[led1]);
  lcd.setCursor(0,1);
  lcd.print(led2_menus[led1][led2]);
  if (led1!=0)
  {
    lcd.setCursor(14,0);
    lcd.print(pot1);
    lcd.setCursor(14,1);
    lcd.print(pot2);
  }
  delay(100);
}
