#include<iostream>
#include<string>
#include<math.h>
using namespace std;

class DHOB
{
public:
    char *hexa;

    int getSize(int X)
    {
        int size = 0;

        while (X != 0)
        {
            X = X / 10;
            size++;
        }
        return size;
    }

    int* getArray(int Bin, int size)
    {
        static int arr[100];
        int y = 10;
        arr[0] = Bin % y;
        for (int i = 1; i < size + 1; i++)
        {
            arr[i] = Bin / y % 10;
            y = y * 10;
        }
        return arr;
    }

    bool Check_Octal(int arr[], int size)
    {
        int c = 0;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] < 0 || arr[i] > 7)
            {
                c++;
                return false;
            }
        }
        if (c == 0)
            return true;
    }

    bool Check_Decimal(int arr[], int size)
    {
        int c = 0;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] < 0 || arr[i] >9)
            {
                c++;
                return false;
            }
        }
        if (c == 0)
            return true;
    }

    bool Check_Binary(int arr[], int size)
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
          
            if (arr[i] < 0 || arr[i]>1)
            {
                count++;
                return false;
            }
        }
        if (count == 0)
            return true;
    }

    int Binary_Decimal(int arr[], int size) // Function 1
    {
        int ans = 0;
        int p = 0;
        for (int i = 0; i < size; i++)
        {
            ans = ans + (arr[i] * pow(2, p));
            p++;
        }
        return ans;
    }

    int Octal_Decimal(int arr[], int size) // Function 2
    {
        int ans = 0;
        int p = 0;
        for (int i = 0; i < size; i++)
        {
            ans = ans + (arr[i] * pow(8, p));
            p++;
        }
        return ans;
    }

    int* Decimal_Binary(int Bin) // Function 3
    {
        static int rem[100];
        int j = 0;
        int b = Bin;
        while (b != 1)
        {
            b = b / 2;
            j++;
        }

        for (int i = 0; i <= j; i++)
        {
            rem[i] = Bin % 2;
            Bin = Bin / 2;
        }
       
        cout << "\nBinary : ";
        for (int i = j; i >= 0; i--)
        {
            cout << rem[i];
        }
        cout << endl << endl;
        return rem;
    }

    void Octal_Binary(int arr[], int Bin, int size) // Function 4
    {
        int num = Octal_Decimal(arr, size);
        int* ar = { 0 };
        ar = Decimal_Binary(num);
    }

    void Binary_Octal(int arr[], int size)  // Function 5

    { // first convert binary into decimal
        int ans = 0;
        int p = 0;

        for (int i = 0; i < size; i++)
        {
            ans = ans + (arr[i] * pow(2, p));
            p++;
        }

        // now converting decimal into Ocatal
        static int rem[100];
        int j = 0;
        int b = ans;
        while (b > 0)
        {
            b = b / 8;
            j++;
        }

        for (int i = 0; i <= j; i++)
        {
            rem[i] = ans % 8;
            ans = ans / 8;
        }
        
        cout << "\nOctal : ";

        for (int i = j - 1; i >= 0; i--)
        {
            cout << rem[i];
        }
        cout << endl << endl;
    }

    void Decimal_Octal(int ans) // Function 6
    {
        static int rem[100];
        int j = 0;
        int b = ans;
        while (b > 0)
        {
            b = b / 8;
            j++;
        }

        for (int i = 0; i <= j; i++)
        {
            rem[i] = ans % 8;
            ans = ans / 8;
        }

        cout << "\nOctal : ";
        for (int i = j - 1; i >= 0; i--)
        {
            cout << rem[i];
        }
    }

    void Decimal_Hexa(int X) // Function 7
    {
        int  rem, i = 0;
        char hexaDecimalNum[50];

        while (X != 0)
        {
            rem = X % 16;
            if (rem < 10)
                rem = rem + 48;
            else
                rem = rem + 55;
            hexaDecimalNum[i] = rem;
            i++;
            X = X / 16;
        }

        cout << "\nHexa Decimal : ";

        for (i = i - 1; i >= 0; i--)
            cout << hexaDecimalNum[i];
        cout << endl;
    }

    void Binary_Hexa(int arr[], int X) // Function 8
    {
        // Binary to Decimal
        int y = Binary_Decimal(arr, X);
        // Decimal to Hexa
        Decimal_Hexa(y);
    }

    void Octal_Hexa(int arr[], int Bin, int size) // Function 9
    {
        // Octa to Binary
                //octal to decimal
        int num = Octal_Decimal(arr, size);
               
        // decimal to binary
        static int rem[100];
        int j = 0;
        int b = num;
        while (b != 1)
        {
            b = b / 2;
            j++;
        }

        for (int i = 0; i <= j; i++)
        {
            rem[i] = num % 2;
            num = num / 2;
        }
        
        int v = 0;
        for (int i = j; i >= 0; i--)          // to get the length of the rem[] array!!!
        {
            v++;
        }
        /*
        rem[i] array is octal to binary (binary here = rem[i]
        Now we have to convert this binary array to hexa ie. binary to hexa
        */

        // Binary to Hexa

        //for binary to decimal we need an array and its size so here (array=rem[i] and size = v (j is not working here idk why)

        int z = Binary_Decimal(rem,v);                       
        Decimal_Hexa(z);
    }

    
    int hexatodecimal(char str[]) // Function 10
    {
        int decnum = 0,num=0;
        int size = strlen(str);

        for (int i = 0; str[i] != '\0'; i++)
        {
            size--;
            if (str[i] >= '0' && str[i] <= '9')
            {
                num = str[i] - 48;
            }

            else if (str[i] >= 'a' && str[i] <= 'f')
            {
                num = str[i] - 87;
            }

            else if (str[i] >= 'A' && str[i] <= 'F')
            {
                num = str[i] - 55;
            }

            decnum = decnum + (num * pow(16, size));
        }

        return decnum;
    }

    int hextobinary(char str[]) // Function 11
    {
        //hex to dec
        int dec = hexatodecimal(str);
        //dec to binary
        Decimal_Binary(dec);

        return 0;
    }

    int hextooctal(char str[]) // Function 12
    {
        //hex to dec
        int dec = hexatodecimal(str);
        //dec to octal
        Decimal_Octal(dec);
        return 0;
    }
};


int main()
{

    DHOB obj;
    int choice1;
    char chararr[100] = {};

    do
    {
        cout << "\n\tWhich Number do you want to Enter?";
        cout << "\n\t1.\tBinary";
        cout << "\n\t2.\tDecimal";
        cout << "\n\t3.\tOctal";
        cout << "\n\t4.\tHexal";
        cout << "\n\t5.\tEXIT PROGRAM";

        cout << "\n\n\tChoice : ";
        cin >> choice1;

        switch (choice1)
        {
            case 1: // CASE ONE
            {
                cout << "\n\n\tEnter Binary Number : ";
                int X;
                cin >> X;

                int size = obj.getSize(X);
                int* arr = obj.getArray(X, size);

                if (!obj.Check_Binary(arr,size))
                {
                    cout << " \n\nGiven Number is not Binary!\n";
                    break;
                }

                else
                {
                    cout << "\n\nWhat do you want to Convert Binary into?";

                    cout << "\n\n1.\tDecimal";
                    cout << "\n2.\tOctal";
                    cout << "\n3.\tHexa Decimal";
                    int choice2;
                    cout << "\n\n\tChoice : ";
                    cin >> choice2;

                    switch (choice2)
                    {
                        case 1:
                        {
                            int Z = obj.Binary_Decimal(arr, size);
                            cout << "\n\nBinary to Decimal";
                            cout<<"\nBinary : "<<X;
                            cout <<"\nDecimal : "<< Z << endl;
                            break;
                        }

                        case 2:
                        {
                            cout << "\n\nBinary to Octal";
                            cout << "\nBinary : " << X;
                            obj.Binary_Octal(arr, size);
                            break;
                        }

                        case 3:
                        {
                            cout << "\nBinary to Hexa Decimal";
                            cout << "\nBinary : " << X;
                            obj.Binary_Hexa(arr, size);
                            break;
                        }

                        default:
                            cout << "\nInvalid Input! Choose from the given Options!\n";
                            break;
                    }
                }

                break;
            }

            case 2: // CASE TWO
            {
                cout << "\n\nEnter Decimal Number : ";
                int X;
                cin >> X;

                int size = obj.getSize(X);
                int* arr = obj.getArray(X, size);

                if (!obj.Check_Decimal(arr, size))
                {
                        cout << " \n\nGiven Number is not Decimal!\n";
                        break;
                }

                else
                {
                    cout << "\n\nWhat do you want to Convert Decimal into?";

                    cout << "\n\n1.\tBinary";
                    cout << "\n2.\tOctal";
                    cout << "\n3.\tHexa Decimal";

                    int choice3;
                    cout << "\n\n\tChoice : ";
                    cin >> choice3;

                    switch (choice3)
                    {
                        case 1:
                        {
                            cout << "\n\nDecimal to Binary";
                            cout << "\nDecimal : " << X;
                            obj.Decimal_Binary(X);
                            break;
                        }

                        case 2:
                        {
                            cout << "\n\nDecimal to Octal";
                            cout << "\nDecimal : " << X;
                            obj.Decimal_Octal(X);
                            break;
                        }

                        case 3:
                        {
                            cout << "\n\nDecimal to Hexa Decimal";
                            cout << "\nDecimal : " << X;

                            obj.Decimal_Hexa(X);
                            break;
                        }
                        default:
                            cout << "\nInvalid Input! Choose from the given Options!\n";
                            break;
                    }
                }

                break;
            }

            case 3:  // CASE THREE
            {
                cout << "\n\nEnter Octal Number : ";
                int X;
                cin >> X;

                int size = obj.getSize(X);
                int* arr = obj.getArray(X, size);

                if (!obj.Check_Octal(arr, size))
                {
                    cout << " \n\nGiven Number is not Octal!\n";
                    break;
                }

                else
                {
                cout << "\n\nWhat do you want to Convert Octal into?";

                cout << "\n\n1.\tBinary";
                cout << "\n2.\tDecimal";
                cout << "\n2.\tHexal Decimal";

                int choice4;
                cout << "\n\n\tChoice : ";
                cin >> choice4;

                switch (choice4)
                {
                        case 1:
                        {
                            cout << "\n\nOctal to Binary";
                            cout << "\nOctal : " << X;

                            obj.Octal_Binary(arr, X, size);
                            break;
                        }

                        case 2:
                        {
                            cout << "\n\nOctal to Decimal";
                            cout << "\nOctal : " << X;


                            int x = obj.Octal_Decimal(arr, size);
                            cout << "\nDecimal : ";
                            cout << x;
                            cout << endl << endl;
                            break;
                        }

                        case 3:
                        {
                            cout << "\n\nOctal to Hexa Decimal";
                            cout << "\nOctal : " << X;

                            obj.Octal_Hexa(arr, X, size);
                            break;
                        }
                        default:
                            cout << "\nInvalid Input! Choose from the given Options!\n";
                            break;
                    }
                }

                break;
            }

            case 4: // CASE FOUR
            { 
                cout << "\n\n\tEnter Hexa Decimal Number : ";
                cin >> chararr;

                cout << "\n\nWhat do you want to Convert Hexa Decimal into?";

                cout << "\n\n1.\tBinary";
                cout << "\n2.\tDecimal";
                cout << "\n3.\tOctal";

                int choice4;
                cout << "\n\n\tChoice : ";
                cin >> choice4;

                switch (choice4)
                {
                    case 1:
                    {
                        cout << "\n\nHexa Decimal to Binary";
                        cout << "\nHexa Decimal : " << chararr;
                        obj.hextobinary(chararr);
                        break;
                    }

                    case 2:
                    {
                        cout << "\n\nHexa Decimal to Decimal";
                        cout << "\nHexa Decimal : " << chararr;

                        int hextodec = obj.hexatodecimal(chararr);
                        cout << "\nDecimal : ";
                        cout << hextodec;
                        cout << endl << endl;
                        break;
                    }

                    case 3:
                    {
                        cout << "\n\nHexa Decimal to Octal";
                        cout << "\nHexa Decimal : " << chararr;

                        obj.hextooctal(chararr);
                        break;
                    }

                    default:
                        cout << "\nInvalid Input! Choose from the given Options!\n";
                        break;
                }
                break;
            }

            case 5: // CASE 5
            {
                exit(0);
            }

            default:
                cout << "\nInvalid Input! Choose from the given Options!\n";
                break;
        }

    }while (1);
    
    return 0;
}
