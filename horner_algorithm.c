#include <stdio.h>


// Array will be the coefficients for our polynomial starting with the coefficient on x^0 to the coefficient on x^n-1
int horners_algorithm(int arr[], int n, int x) {

	
	// We will store the last number as our initial sum
	int sum = arr[n];
	
	// Simply loop backwards. Skip the last element since we already have it in sum
	for (int i = n-1; i >= 0; i--) {
		
		// Simply multiply the current sum by our x value, and add the coefficient for the term of a lower power.
		sum = (sum * x) + arr[i];
	}
	
	
	return sum;
		
}



int main () {
	
	// This example array will represent 2x^3 + 3x^2 - 4x + 1
	int arr[] = {1, -4, 3, 2};
	
	
	
	int len = sizeof(arr) / sizeof(arr[0]);
	
	
	int x = 8;
	printf("The polynomial at %d evaluates to: %d\n", x, horners_algorithm(arr, len - 1, x));
	
	
	
	// Print the coefficients in polynomial form. We start at the end and go until the second to last element
	for (int i = len-1; i > 0; i--) {
		printf("%dx^%d + ", arr[i], i);
		
	}
	
	// Print out second to last element outside the loop since we do not want to add exponent or add any term after that.
	printf("%d", arr[0]);

	
	
	return 0;

}