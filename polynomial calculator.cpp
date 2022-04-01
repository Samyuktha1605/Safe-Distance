#include <stdio.h>
#include<stdlib.h>
#include <bits/stdc++.h>

using namespace std;

struct node
{
    float coeff;
    int deg;
    struct node *next;
}*poly1,*poly2,*sumpoly,*diffpoly,*prodpoly,*simpprod;

// Function to add a new node at the end of a linked list
node* addnode(node* start, float coeff, int deg)
{
    // Create a new node
    node* newnode = new node;
    newnode->coeff = coeff;
    newnode->deg = deg;
    newnode->next = NULL;

    // If linked list is empty
    if (start == NULL)
        return newnode;

    // If linked list has nodes
    node* ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = newnode;

    return start;
}

//Function to form a new polynomial
struct node * createlist(struct node *h,int l)
{
    h=(struct node *)malloc(sizeof(struct node));

    if(h==NULL)
    {
        printf("\nUnable to allocate memory!");
    }

    else
    {
        struct node *newnode,*temp;
        int i;
        float data;

        printf("Enter coefficient of x^%d : ",l);

        scanf("%f",&data);

        h->coeff=data;
        h->deg=l;
        h->next=NULL;
        temp=h;

        for(i=l-1;i>=0;i--)
        {
            newnode=(struct node *)malloc(sizeof(struct node));

            if(newnode==NULL)
            {
            printf("\nUnable to allocate memory!");
            break;
            }

            else
            {
            printf("Enter coefficient of x^%d : ",i);
            scanf("%f",&data);
                if(data!=0)
                {
                    newnode->coeff=data;
                    newnode->deg=i;
                    newnode->next=NULL;
                    temp->next=newnode;

                    temp=temp->next;
                }

            }
        }
    }
    return h;
}

// Function To Display The Linked list
void printList(struct node* ptr)
{
    while (ptr->next != NULL)
    {
        if(ptr->coeff!=0)
        {
            cout << ptr->coeff << "x^" << ptr->deg ;
            if( ptr->next!=NULL && ptr->next->coeff >0)
                cout << " + ";
        }
        ptr = ptr->next;
    }
    if(ptr->coeff!=0)
        cout << ptr->coeff << "\n";
}

//function to display polynomials
void display(struct node* node)
{
    int count = 0;
    while (node->next == NULL || node->coeff == 0)
    {
        cout<<"0";
        return;
        break;
    }

    while (node->next != NULL && node->coeff != 0)
    {
        if (count == 0)
        cout << node->coeff;
        else
        cout << abs(node->coeff);

        count++;

        if (node->deg != 0)
        cout << "x^" << node->deg;
        node = node->next;

        if (node->next != NULL)
            if (node->coeff > 0)
            cout << " + ";
            else
            cout << " - ";
    }
    cout << "\n";
}

//Add two polynomials
void add(struct node *poly1,struct node *poly2)
{
    sumpoly=(struct node *)malloc(sizeof(struct node));
    int cnt=0;

    if(sumpoly==NULL)
    {
        printf("\nUnable to allocate memory!");
    }

    else
    {
        struct node *temp1=poly1;
        struct node *temp2=poly2;
        struct node *temp=sumpoly;

        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->deg>temp2->deg)
            {
                temp->deg=temp1->deg;
                temp->coeff=temp1->coeff;
                temp1=temp1->next;
                cnt++;
            }

            else if(temp1->deg<temp2->deg)
            {
                temp->deg=temp2->deg;
                temp->coeff=temp2->coeff;
                temp2=temp2->next;
                cnt++;
            }

            else
            {
                temp->deg=temp1->deg;
                temp->coeff=temp1->coeff+temp2->coeff;
                temp1=temp1->next;
                temp2=temp2->next;
                cnt++;
            }

            if(temp1 && temp2)
            {
                temp->next=(struct node *)malloc(sizeof(struct node));
                temp=temp->next;
                temp->next=NULL;
            }
        }

        while(temp1 || temp2)
        {
            temp->next=(struct node *)malloc(sizeof(struct node));
            temp=temp->next;
            temp->next=NULL;

            if(temp1)
            {
                temp->deg=temp1->deg;
                temp->coeff=temp1->coeff;
                temp1=temp1->next;
                cnt++;
            }

            if(temp2)
            {
                temp->deg=temp2->deg;
                temp->coeff=temp2->coeff;
                temp2=temp2->next;
                cnt++;
            }
        }

    }
    printf("\n\nThe sum polynomial is:\n");
    printList(sumpoly);
}

//Subtract
void subtract(struct node *poly1,struct node *poly2)
{
    diffpoly=(struct node *)malloc(sizeof(struct node));
    int cnt=0;

    if(diffpoly==NULL)
    {
        printf("\nUnable to allocate memory!");
    }

    else
    {
        struct node *temp1=poly1;
        struct node *temp2=poly2;
        struct node *temp=diffpoly;

        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->deg>temp2->deg)
            {
                temp->deg=temp1->deg;
                temp->coeff=temp1->coeff;
                temp1=temp1->next;
                cnt++;
            }

            else if(temp1->deg<temp2->deg)
            {
                temp->deg=temp2->deg;
                temp->coeff=-1*(temp2->coeff);
                temp2=temp2->next;
                cnt++;
            }

            else
            {
                temp->deg=temp1->deg;
                temp->coeff=temp1->coeff-temp2->coeff;
                temp1=temp1->next;
                temp2=temp2->next;
                cnt++;
            }

            if(temp1 && temp2)
            {
                temp->next=(struct node *)malloc(sizeof(struct node));
                temp=temp->next;
                temp->next=NULL;
            }
        }

        while(temp1 || temp2)
        {
            temp->next=(struct node *)malloc(sizeof(struct node));
            temp=temp->next;
            temp->next=NULL;

            if(temp1)
            {
                temp->deg=temp1->deg;
                temp->coeff=temp1->coeff;
                temp1=temp1->next;
                cnt++;
            }

            if(temp2)
            {
                temp->deg=temp2->deg;
                temp->coeff=-1*(temp2->coeff);
                temp2=temp2->next;
                cnt++;
            }
        }

    }
    printf("\n\nThe difference polynomial is:\n");
    printList(diffpoly);
}

//Simplification of like terms
void simplify(struct node* proppoly,int n)
{
    simpprod=(struct node *)malloc(sizeof(struct node));

    if(simpprod==NULL)
    {
        printf("\nUnable to allocate memory!");
    }

    else
    {
        struct node*temp=simpprod;
        struct node *temp2=prodpoly;

        for(int i=n;i>=0;i--)
        {
            temp2=prodpoly;
            temp->deg=i;
            temp->coeff=0;
            while(temp2!=NULL)
            {
                if(temp2->deg==i)
                {
                   temp->coeff+=temp2->coeff;
                }
                temp2=temp2->next;
            }

            temp->next=(struct node *)malloc(sizeof(struct node));
            temp=temp->next;
            temp->next=NULL;

        }
    }
    printf("\n\nThe product polynomial is:\n");
    printList(simpprod);
}

//Multiplication of two polynomials
void mult(struct node* poly1,struct node*poly2)
{
    prodpoly=(struct node *)malloc(sizeof(struct node));
    int cnt=0;

    if(prodpoly==NULL)
    {
        printf("\nUnable to allocate memory!");
    }

    else
    {
        struct node *temp1=poly1;
        struct node *temp2=poly2;
        struct node *temp=prodpoly;

        while(temp2!=NULL)
        {
            temp1=poly1;
            while(temp1!=NULL)
            {
                temp->deg=temp1->deg+temp2->deg;
                temp->coeff=temp1->coeff*temp2->coeff;
                temp1=temp1->next;

                temp->next=(struct node *)malloc(sizeof(struct node));
                temp=temp->next;
                temp->next=NULL;

                cnt++;
            }
            temp2=temp2->next;
        }
    }
    simplify(prodpoly,prodpoly->deg);
}

//function to store the quotient
void quotientpoly(float mul_c,int diff,struct node* quo)
{
    while (quo->next != NULL)
    {
        quo = quo->next;
    }
    quo->deg = diff;
    quo->coeff = mul_c;
    quo->next = (struct node*)malloc(sizeof(struct node));
    quo = quo->next;
    quo->next = NULL;
}

//function used when subtraction has to be performed during polynomial division
void polysub(int diff,float mulc,struct node* poly)
{
    while (poly->next != NULL)
    {
        poly->deg += diff;
        poly->coeff *= mulc;
        poly = poly->next;
    }
}

void tocopy(struct node* r,struct node** copy)
{
    // Copy the values of r in the
    // polynomial copy
    while (r != NULL) {

        struct node* z
            = (struct node*)malloc(sizeof(struct node));

        // Store coeffcient and deger
        z->coeff = r->coeff;
        z->deg = r->deg;
        z->next = NULL;

        struct node* dis = *copy;
        if (dis == NULL) {
            *copy = z;
        }
        else {
            while (dis->next != NULL) {
                dis = dis->next;
            }
            dis->next = z;
        }
        r = r->next;
    }
}

// Function to subtract two polynomial
void polySub(struct node* poly1,struct node* poly2,struct node* poly)
{

    // Compute until poly1 and poly2 is empty
    while (poly1->next && poly2->next) {

        // If deger of 1st polynomial
        // > 2nd, then store 1st as
        // it is and move its pointer
        if (poly1->deg > poly2->deg) {

            poly->deg = poly1->deg;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
            poly->next
                = (struct node*)malloc(sizeof(struct node));
            poly = poly->next;
            poly->next = NULL;
        }
        else if (poly1->deg < poly2->deg)
        {
            poly->deg = poly2->deg;
            poly->coeff = -1 * poly2->coeff;
            poly2 = poly2->next;
            poly->next
                = (struct node*)malloc(
                    sizeof(struct node));
            poly = poly->next;
            poly->next = NULL;
        }
        else
        {
            if ((poly1->coeff - poly2->coeff)!= 0)
            {
                poly->deg = poly1->deg;
                poly->coeff = (poly1->coeff - poly2->coeff);

                poly->next = (struct node*)malloc(sizeof(struct node));
                poly = poly->next;
                poly->next = NULL;
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1->next || poly2->next)
    {
        if (poly1->next)
        {
            poly->deg = poly1->deg;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }

        if (poly2->next)
        {
            poly->deg = poly2->deg;
            poly->coeff = -1 * poly2->coeff;
            poly2 = poly2->next;
        }

        poly->next = (struct node*)malloc(sizeof(struct node));
        poly = poly->next;
        poly->next = NULL;
    }
}

// Function to divide two polynomials
void dividepolys(struct node* poly1,struct node* poly2)
{
    struct node *rem = NULL, *quo = NULL;

    quo = (struct node*)malloc(sizeof(struct node));
    quo->next = NULL;

    struct node *q = NULL, *r = NULL;

    tocopy(poly1, &q);

    tocopy(poly2, &r);

    while (q != NULL && (q->deg >= poly2->deg))
    {
        int diff = q->deg - poly2->deg;
        float mul_c = (q->coeff / poly2->coeff);
        struct node* q2 = NULL;

        quotientpoly(mul_c, diff,quo);
        tocopy(r, &q2);
        polysub(diff, mul_c, q2);

        struct node* store = NULL;
        store = (struct node*)malloc(sizeof(struct node));
        polySub(q, q2, store);

        q = store;
        free(q2);
    }

    cout << "\nQUOTIENT: ";
    display(quo);//print quotient

    // Print the remainder
    cout << "REMAINDER: ";
    rem=q;
    display(rem);//print remainder

}

//to find the the value of the polynomial for the given value of x
void value(struct node*h,int k,int n)
{
     int val=0;
     if(h==NULL)
     cout<<"\nList is empty!\n";
     else
     {
         struct node *temp;
         temp=h;
         for(int i=0;i<=n;i++)
         {
             if(temp->coeff!=0)
             {
                 val+=(temp->coeff) * (pow(k,(temp->deg)));
             }
             temp=temp->next;
         }
     }
     cout<<"\n";
     printList(h);

     cout<<"\n\nf("<<k<<")= "<<val;//print the value
}

//Scalar multiplication of a polynomial
struct node* scalarmultiply(node* poly1,float k,node* result)
{

    // Creating a pointer and storing the address of the polynomial
    node *ptr1;
    ptr1 = poly1;
    while (ptr1 != NULL)
    {
            float coeff;
            int deg;

            // Multiply the coefficient with k and store it in coeff
            coeff = ptr1->coeff * k;

            deg = ptr1->deg;

            //creating a new node
            result = addnode(result, coeff, deg);

        ptr1 = ptr1->next;
    }


    return result;
}

int main()
{
    int choice,k,h;

    cout<<"\t\t**********************\n\t\tPOLYNOMIAL CALCULATOR\n\t\t**********************\n";

    while(1)
    {
        struct node *poly = NULL,*scmul=NULL,*result=NULL;
        int h1,h2,c,i;

        printf("\n\n\t1. Add\n\t2. Subtract\n\t3. Multiply\n\t4. Divide\n\t5. Find value of f(x) for a specific x\n\t6. Scalar multiplication\n\nEnter choice(Press 0 to EXIT) : ");
        scanf("%d",&choice);

        if(choice==1 || choice==2 || choice==3 || choice==4)
        {
            int deg1,deg2;

            printf("\nEnter highest degree of polynomial 1: ");
            scanf("%d",&deg1);
            poly1=createlist(poly1,deg1);
            printf("\nFirst polynomial: ");
            printList(poly1);

            printf("\nEnter highest degree of polynomial 2: ");
            scanf("%d",&deg2);
            poly2=createlist(poly2,deg2);
            printf("\nSecond polynomial: ");
            printList(poly2);
        }

        if(choice==5)
        {

                if(choice==5)
                    cout<<"\nEnter the value of k to find f(k): ";
                else
                    cout<<"\nEnter the value of k to find kf(x): ";
                cin>>k;

                cout<<"\nEnter the highest degree of the polynomial : ";
                cin>>h;
        }

        switch(choice)
        {
            case 0:
                exit(0);
            case 1:
                add(poly1,poly2);
                break;

            case 2:
                subtract(poly1,poly2);
                break;

            case 3:
                mult(poly1,poly2);
                break;

            case 4:
                dividepolys(poly1, poly2);
                break;

            case 5:
                poly=createlist(poly1,h);

                value(poly,k,h);
                break;

            case 6:
                float coeff,k;
                int power,deg;
                //creating a polynomial
                cout<<"\n\nENTER THE HIGHEST POWER OF THE POLYNOMIAL : ";
                cin>>deg;
                int i=deg;
                cout<<"\n";
                while(deg>=0)
                {
                    cout<<"Enter the coefficient of x^"<<deg<<" : ";
                    cin>>coeff;
                    scmul=addnode(scmul,coeff,deg);
                    deg--;
                }

                // Displaying the polynomial
                cout << "\nTHE POLYNOMIAL: ";
                printList(scmul);
                cout<<"\nENTER THE SCALAR YOU WOULD LIKE TO MULTIPLY THE POLYNOMIAL WITH : ";
                cin>>k;

                //calling function to perform scalar multiplication
                result = scalarmultiply(scmul,k,result);

                // Displaying Resultant Polynomial
                cout << "\nPOLYNOMIAL AFTER SCALAR MULTIPLICATION:  ";
                printList(result);
                break;
        }
        cout<<"\n\t\t*********************";
    }

    return 0;
}
