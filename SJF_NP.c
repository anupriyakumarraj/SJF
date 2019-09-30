#include "pch.h"
#include<stdio.h>

int main()
{
	int burst_time[100], arr_time[100], wait_time[100], total_time[100], temp, j, ta = 0, sum = 0;
	int i = 0, n, p[100], lowest, b_temptime = 0, k = 1;
	float sum_total = 0, sum_waiting = 0, waiting_mean = 0, total_mean = 0;
	printf(" -------SJF Algorithm ( Non-Preemptive )-------\n");
	printf("\nEnter the No. of processes :");
	scanf_s("%d", &n);

	/*Initializing p for taking number of processes*/

	for (i = 0; i < n; i++)
	{
		p[i] = i + 1;

	}

	/*Arrival and burst time values for each process*/

	for (i = 0; i < n; i++)
	{
		printf("\tEnter the arrival time of process %d :", i + 1);
		scanf_s(" %d", &arr_time[i]);
		printf("\tEnter the burst time of process %d :", i + 1);
		scanf_s(" %d", &burst_time[i]);

	}

	/*Sorting values based on the arrival time*/

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (arr_time[i] < arr_time[j])
			{
				temp = p[j];
				p[j] = p[i];
				p[i] = temp;
				temp = arr_time[j];
				arr_time[j] = arr_time[i];
				arr_time[i] = temp;
				temp = burst_time[j];
				burst_time[j] = burst_time[i];
				burst_time[i] = temp;
			}
		}
	}

	/*Table organization*/

	for (j = 0; j < n; j++)
	{
		b_temptime = b_temptime + burst_time[j];
		lowest = burst_time[k];
		for (i = k; i < n; i++)
		{
			if (b_temptime >= arr_time[i] && burst_time[i] < lowest)
			{
				temp = p[k];
				p[k] = p[i];
				p[i] = temp;
				temp = arr_time[k];
				arr_time[k] = arr_time[i];
				arr_time[i] = temp;
				temp = burst_time[k];
				burst_time[k] = burst_time[i];
				burst_time[i] = temp;
			}
		}
		k++;
	}
	wait_time[0] = 0;
	for (i = 1; i < n; i++)
	{
		sum = sum + burst_time[i - 1];
		wait_time[i] = sum - arr_time[i];
		sum_waiting = sum_waiting + wait_time[i];
	}

	waiting_mean = (sum_waiting / n);
	for (i = 0; i < n; i++)
	{
		ta = ta + burst_time[i];
		total_time[i] = ta - arr_time[i];
		sum_total = sum_total + total_time[i];
	}

	total_mean = (sum_total / n);

	printf("************************");
	printf("\n OUTPUT:-");
	printf("\nProcess\t Arrival Time \t Burst Time\t Waiting Time \t Turn-around Time");
	for (i = 0; i < n; i++)
	{
		printf("\n P%d\t\t %d\t\t %d\t\t %d\t\t%d", p[i], arr_time[i], burst_time[i], wait_time[i], total_time[i]);
	}

	printf("\n\nMEAN WAITING TIME : %f", waiting_mean);
	printf("\nMEAN TURN AROUND TIME : %f", total_mean);
	return 0;
}