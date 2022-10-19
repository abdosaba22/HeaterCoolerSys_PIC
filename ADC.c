#include "ADC.h"

void ADC_Init()
{
    ADCON0 = 0x41;  // Turn ADC ON, Select AN0 Channel, ADC Clock = Fosc/8
    ADCON1 = 0x80;  // All 8 Channels Are Analog, Result is "Right-Justified"
                    // ADC Clock = Fosc/8
}
unsigned int ADC_Read(unsigned char ANC)
{
    if(ANC<0 || ANC>7)    // Check Channel Number Validity
    { return 0;}
    ADCON0 &= 0x11000101; // Clear The Channel Selection Bits
    ADCON0 |= ANC<<3;     // Select The Required Channel (ANC)
                          // Wait The Aquisition Time
    delay_us(30);       // The Minimum Tacq = 20us, So That should be enough
    ADCON0.GO_DONE= 1;          // Start A/D Conversion
    while(ADCON0.GO_DONE); // Polling GO_DONE Bit
                               // Provides Delay Until Conversion Is Complete
    return ((ADRESH << 8) + ADRESL); // Return The Right-Justified 10-Bit Result
}