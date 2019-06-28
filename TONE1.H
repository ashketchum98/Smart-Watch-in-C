void tone1()
{
while(!kbhit())
{
sound(330);
delay(100);
sound(300);
delay(100);
sound(330);
delay(100);
sound(230);
delay(100);
nosound();
}
}