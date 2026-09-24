#include <stdio.h>
#include <ctype.h>

int main()
{
    double temperature;
    double celsius;
    double converted;
    char originalScale;
    char targetScale;

    printf("Enter the temperature value: ");
    scanf("%lf", &temperature);

    printf("Enter the original scale (C, F, or K): ");
    scanf(" %c", &originalScale);

    printf("Enter the scale to convert to (C, F, or K): ");
    scanf(" %c", &targetScale);

    // Allow lowercase letters too
    originalScale = toupper(originalScale);
    targetScale = toupper(targetScale);

    // First convert the original temperature to Celsius
    if (originalScale == 'C')
    {
        celsius = temperature;
    }
    else if (originalScale == 'F')
    {
        celsius = (temperature - 32.0) * 5.0 / 9.0;
    }
    else if (originalScale == 'K')
    {
        celsius = temperature - 273.15;
    }
    else
    {
        printf("Invalid original temperature scale.\n");
        return 1;
    }

    // Convert Celsius to the requested scale
    if (targetScale == 'C')
    {
        converted = celsius;
    }
    else if (targetScale == 'F')
    {
        converted = (celsius * 9.0 / 5.0) + 32.0;
    }
    else if (targetScale == 'K')
    {
        converted = celsius + 273.15;
    }
    else
    {
        printf("Invalid target temperature scale.\n");
        return 1;
    }

    printf("Converted temperature: %.2f %c\n", converted, targetScale);

    // Categories are determined using Celsius
    if (celsius < 0)
    {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Bundle up and stay warm!\n");
    }
    else if (celsius < 10)
    {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket!\n");
    }
    else if (celsius < 25)
    {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: Enjoy the weather!\n");
    }
    else if (celsius < 35)
    {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Drink lots of water!\n");
    }
    else
    {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors and keep cool!\n");
    }

    return 0;
}