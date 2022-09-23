#include <bits/stdc++.h>
#include "graphics.h"

using namespace std;


class sorting
{
public:
    void swapLines(int i, int j, int x, int y,int size)
    {

        setcolor(GREEN);
        line(i, size, i, size - x);

        setcolor(BLACK);
        line(i, size, i, size - x);

        setcolor(WHITE);
        line(i, size, i, size - y);

        setcolor(GREEN);
        line(j, size, j, size - y);

        setcolor(BLACK);
        line(j, size, j, size - y);

        setcolor(WHITE);
        line(j, size, j, size - x);
    }
 
    void makeRandomArray(vector<int> &integers,int size,int gap)
    {
    	      for (int i = 0; i <= size; i++)
        {
        	integers.push_back(i);
            
        }
        random_shuffle(integers.begin(), integers.end());
         	     for (int i = 1; i <= gap * size; i += gap)
    {
        line(i, size, i, (size - integers[i / gap]));
    }
    }
    
    void openGraph(int size,int gap)
    {
    	int graphicsDriver = DETECT, gm;
    	int width;
    	initgraph(&graphicsDriver, &gm, NULL);
    	width = initwindow(gap * size + 1, size + 1,"Sorting Visualizer");
    	setcurrentwindow(width);
	}

    void bubbleSort(vector<int> &integers,int size,int gap)
    {
        int temp;
        for (int i = 1; i < integers.size(); i++)
        {
            for (int j = 0; j < integers.size() - i; j++)
            {
                if (integers[j] > integers[j + 1])
                {
                    swap(integers[j], integers[j + 1]);

                    swapLines(gap * j + 1,
                              gap * (j + 1) + 1,
                              integers[j + 1],
                              integers[j],size);
                }
            }
        }
    }

    void selectionSort(vector<int> &integers,int size,int gap)
    {
        int min, temp, i, j;
        for (i = 0; i < integers.size() - 1; i++)
        {
            min = i;
            for (j = i + 1; j < integers.size(); j++)
            {
                if (integers[j] < integers[min])
                {
                    min = j;
                }
            }
            delay(1000);
            swap(integers[min], integers[i]);

            swapLines(gap * i + 1,
                      gap * (min) + 1,
                      integers[min],
                      integers[i],size);
        }
    }

    void insertionSort(vector<int> &integers,int size ,int gap)
    {
        int N = integers.size();
        int i, j, key;

        for (i = 1; i < N; i++)
        {
            j = i;
            while (j > 0 and integers[j] < integers[j - 1])
            {
                swap(integers[j], integers[j - 1]);
                swapLines(gap * (j - 1) + 1, gap * j + 1, integers[j], integers[j - 1],size);
                j -= 1;
            }
        }
    }

    void CocktailSort(vector<int> &integers,int size,int gap)
    {
        bool swapped = true;
        int start = 0;
        int end = integers.size() - 1;

        while (swapped)
        {
            swapped = false;
            for (int i = start; i < end; ++i)
            {
                if (integers[i] > integers[i + 1])
                {

                    swap(integers[i], integers[i + 1]);
                    swapLines(gap * i + 1,
                              gap * (i + 1) + 1,
                              integers[i + 1],
                              integers[i],size);

                    swapped = true;
                }
            }

            if (!swapped)
                break;
            swapped = false;

            --end;
            for (int i = end - 1; i >= start; --i)
            {
                if (integers[i] > integers[i + 1])
                {
                    swap(integers[i], integers[i + 1]);
                    swapLines(gap * i + 1,
                              gap * (i + 1) + 1,
                              integers[i + 1],
                              integers[i],size);
                    swapped = true;
                }
            }
            ++start;
        }
    }

    int partition(vector<int> &integers, int start, int end,int size,int gap)
    {
        int pivot = integers[start];
        int i = start;
        int j = end;
        while (i < j)
        {
            while (integers[i] <= pivot)
                i++;
            while (integers[j] > pivot)
                j--;

            if (i < j)
            {
                swap(integers[i], integers[j]);
                delay(100);
                swapLines(gap * i + 1,
                          gap * (j) + 1,
                          integers[j],
                          integers[i],size);
            }
        }
        swap(integers[start], integers[j]);
        delay(100);
        swapLines(gap * start + 1,
                  gap * (j) + 1,
                  integers[j],
                  integers[start],size);

        return j;
    }
    void quickSort(vector<int> &integers, int start, int end,int size,int gap)
    {
        if (start < end)
        {
            int pivot = partition(integers, start, end,size,gap);
            quickSort(integers, start, pivot - 1,size,gap);
            quickSort(integers, pivot + 1, end,size,gap);
        }
    }
    void oddEvenSort(vector<int> &arr,int size,int gap)
    {
        bool isSorted = false;

        while (!isSorted)
        {
            isSorted = true;

            for (int i = 1; i <= arr.size() - 2; i = i + 2)
            {
                if (arr[i] > arr[i + 1])
                {
                    swap(arr[i], arr[i + 1]);
                    swapLines(gap * i + 1,
                              gap * (i + 1) + 1,
                              arr[i + 1],
                              arr[i],size);

                    isSorted = false;
                }
            }
            for (int i = 0; i <= arr.size() - 2; i = i + 2)
            {
                if (arr[i] > arr[i + 1])
                {
                    swap(arr[i], arr[i + 1]);
                    swapLines(gap * i + 1,
                              gap * (i + 1) + 1,
                              arr[i + 1],
                              arr[i],size);
                    isSorted = false;
                }
            }
        }

        return;
    }
};

int main()
{

    sorting s;
    	int size;
    	int gap=3;
    vector<int> integers;
    int choice;
    cout << "			------Welcome To The Sorting Visualizer------					" << endl;
    cout << endl;
    
    cout<<"		Please enter the size of array you want to sort(MAX SIZE=600): ";
    cin>>size;
    do
    {	
    system("cls");
    cout << "			Please select which algorithm do you want to apply.			" << endl;
    cout<<endl;
    cout << "					1)Bubble Sort" << endl;
    cout << "					2)Selection Sort" << endl;
    cout << "					3)Insertion Sort" << endl;
    cout << "					4)Cocktail Sort" << endl;
    cout << "					5)Quick Sort" << endl;
    cout << "					6)Odd/Even Sort" << endl;
    cout<<  "					7)Exit"<<endl;
    cout<<endl;
    cout<<"Your choice: ";
    cin >> choice;
  
    	s.openGraph(size,gap);
    	s.makeRandomArray(integers,size,gap);
    	
    	cout<<"The array before sorting"<<endl;
    	for(int i=0;i<integers.size();i++)
    	{
    		cout<<integers[i]<<" ";
		}
		cout<<endl;
		system("pause");
    switch (choice)
    {
    case 1:
    	
        s.bubbleSort(integers,size,gap);
    
        break;
    case 2:
        s.selectionSort(integers,size,gap);

        break;
    case 3:
        s.insertionSort(integers,size,gap);

        break;
    case 4:
        s.CocktailSort(integers,size,gap);

        break;
    case 5:
        s.quickSort(integers, 0, size,size,gap);

        break;
    case 6:
        s.oddEvenSort(integers,size,gap);

        break;
    case 7:
        exit(0);
        break;

    default:
        cout << "Please enter valid input" << endl;
        break;
    }
    cout<<"Array of "<<size<<" integers is sorted. "<<endl;
    for (int i = 0; i < size; i++)
    {
        cout << integers[i] << " ";
    }
    system("pause");
    closegraph();
    system("cls");
	
	}while(choice!=7);
  
    cout << endl;
    delay(5000);
    

    return 0;
}