#include <Arduino.h>
#include <time.h>

void setup() 
{

  Serial.begin(115200);
  // Set the RTC time manually (YYYY, MM, DD, HH, MM, SS)
  struct tm t = {0};
  t.tm_year = 2024 - 1900; // Year (since 1900)
  t.tm_mon = 6; // Month (0-11, January = 0)
  t.tm_mday = 1; // Day
  t.tm_hour = 11; // Hours (0-23)
  t.tm_min = 8; // Minutes
  t.tm_sec = 0; // Seconds
  time_t t_of_day = mktime(&t);
  struct timeval now = { .tv_sec = t_of_day };
  settimeofday(&now, NULL); // Set system time
  Serial.println("RTC Time Set!");

}


void loop() 
{

  struct tm timeinfo;
  time_t now;
  time(&now);
  localtime_r(&now, &timeinfo);
  Serial.print("Time: ");
  Serial.print(timeinfo.tm_hour);
  Serial.print(":");
  Serial.print(timeinfo.tm_min);
  Serial.print(":");
  Serial.println(timeinfo.tm_sec);
  delay(1000);

}