#pragma once  // Ensures the file is included only once during compilation

/// <summary>
/// Adds two integers.
/// </summary>
/// <param name="a">First integer.</param>
/// <param name="b">Second integer.</param>
/// <returns>The sum of a and b.</returns>
extern "C" __declspec(dllexport) int Add(int a, int b);

