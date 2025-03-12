#include <stdio.h>

// Converts Celsius to Fahrenheit using the formula: F = (9/5)C + 32
float celsius_to_fahrenheit(float celsius) 
{
    return (9.0 / 5.0) * celsius + 32;
}

// Converts Fahrenheit to Celsius using the formula: C = (5/9)(F - 32)
float fahrenheit_to_celsius(float fahrenheit) 
{
    return (5.0 / 9.0) * (fahrenheit - 32);
}

// Converts Celsius to Kelvin using the formula: K = C + 273.15
float celsius_to_kelvin(float celsius) 
{
    return celsius + 273.15;
}

// Converts Kelvin to Celsius using the formula: C = K - 273.15
float kelvin_to_celsius(float kelvin) 
{
    return kelvin - 273.15;
}

// Converts Fahrenheit to Kelvin by first converting to Celsius, then Kelvin
float fahrenheit_to_kelvin(float fahrenheit) 
{
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

// Converts Kelvin to Fahrenheit by first converting to Celsius, then Fahrenheit
float kelvin_to_fahrenheit(float kelvin) 
{
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

// This function categorizes the temperature into five predefined ranges and gives an advisory message
void categorize_temperature(float celsius) 
{
    if (celsius < 0) 
    {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: It's freezing! Stay warm.\n");
    } 
    else if (celsius < 10) 
    {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } 
    else if (celsius < 25) 
    {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: You should feel comfortable.\n");
    } 
    else if (celsius < 35) 
    {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Stay hydrated and wear light clothing.\n");
    } 
    else 
    {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Avoid prolonged exposure to the sun.\n");
    }
}

int main() 
{
    float temp_input, temp_output;
    int input_scale, output_scale;

    // This loop keeps prompting the user for temperature input and conversion choice
    while (1) 
    {
        printf("\nEnter the temperature (negative Kelvin to STOP): ");
        scanf("%f", &temp_input); // This scans the user input and stores it in temp_input

        // If the user enters an invalid Kelvin value, terminate the program
        if (temp_input < 0) 
        {
            printf("Invalid Kelvin temperature detected. Exiting.\n");
            break;
        }

        // This asks the user to select the current temperature scale
        printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &input_scale);

        // This asks the user to select the desired target scale
        printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &output_scale);

        // If user selects the same scale, show an error and restart the loop
        if (input_scale == output_scale) 
        {
            printf("Invalid conversion: Cannot convert to the same scale.\n");
            continue;
        }

        // This block performs the conversion based on the user's choices
        if (input_scale == 1 && output_scale == 2) 
        {
            temp_output = celsius_to_fahrenheit(temp_input);
        } 
        else if (input_scale == 1 && output_scale == 3) 
        {
            temp_output = celsius_to_kelvin(temp_input);
        } 
        else if (input_scale == 2 && output_scale == 1) 
        {
            temp_output = fahrenheit_to_celsius(temp_input);
        } 
        else if (input_scale == 2 && output_scale == 3) 
        {
            temp_output = fahrenheit_to_kelvin(temp_input);
        } 
        else if (input_scale == 3 && output_scale == 1) 
        {
            temp_output = kelvin_to_celsius(temp_input);
        } 
        else if (input_scale == 3 && output_scale == 2) 
        {
            temp_output = kelvin_to_fahrenheit(temp_input);
        } 
        else 
        {
            printf("Invalid choice! Please enter a valid option.\n");
            continue;
        }

        // Displays the converted temperature
        printf("Converted temperature: %.2f\n", temp_output);

        // This calls the categorization function only for Celsius values
        if (output_scale == 1) 
        {
            categorize_temperature(temp_output);
        }
    }

    return 0;
}
