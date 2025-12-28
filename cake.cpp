#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ========================== ADMIN ==========================
// ========================== STRUCTURE FOR ADMIN ==========================
struct AdminNode 
{
    string username;      
    string password;      
    AdminNode* next;      
    AdminNode( string user, string pass )
	{
	    username = user;
	    password = pass;
		next = nullptr; 
	} 
};
// ========================== STRUCTURE FOR CUSTOMER  ==========================
struct CustomerNode 
{
    int customerId;      
    string name;        
    string email;       
    CustomerNode* next;  
    CustomerNode( int id, string n, string e )
    {
    	customerId = id;
    	name = n;
		email = e;
		next = nullptr; 
	}
};
// ========================== STRUCTURE FOR CAKE ==========================
struct CakeNode 
{
    string flavor;
    string description;
    double price;
    string size;
    CakeNode* next;
    CakeNode( string fl, string desc, double pr, string sz ) 
    {
    	flavor = fl;
    	description = desc;
		price = pr;
		size = sz;
		next = nullptr; 
	}
};
// ========================== STRUCTURE FOR ORDER ==========================
struct OrderNode 
{
    int orderId;         
    int customerId;      
    string orderStatus;  
    OrderNode* next;    
    OrderNode(int id, int customer, string status)
	{
    	orderId = id;
    	customerId = customer;
		orderStatus = status;
		next = nullptr; 
	} 
};
// ========================== STRUCTURE FOR CAKE DISCOUNT ==========================
struct cakeNode 
{
    int id;
    string name;
    double price;
    double discount; 
    cakeNode* next;
};
// ========================== STRUCTURE FOR FINANCIAL ==========================
struct financial 
{
    string flavor;
    string size;
    int quantity;
    double totalPrice;
};
// ========================== STRUCTURE FOR DELIVERY =========================
struct DeliveryControlNode 
{
    int personnelId;         
    string name;              
    string status;            
    DeliveryControlNode* next;  
    DeliveryControlNode( int id, string n, string stat )
	{
    	personnelId = id;
    	name = n;
		status = stat;
		next = nullptr; 
	}
};

// ========================== CUSTOMER ==========================
// ========================== STRUCTURE FOR CUSTOMER ==========================
struct CustomerNodes 
{
    string name, email, username, password, mobile;
    CustomerNodes* next;
    CustomerNodes( string n, string e, string m, string u, string p)
    {
    	name = n;
		email = e;
		mobile = m;
	    username = u;
	    password = p;
		next = nullptr; 
	}
};
// ========================== STRUCTURE FOR ORDERS ==========================
struct OrderNodes 
{
    string customerName;
    int cakeNo, quantity, pricePerCake, toppingNo, toppingPrice;
    char cakeSize;
    bool withTopping;
    OrderNodes* next;
    OrderNodes( string n, int cn, int cp, int q, int tn=0, int tp=0, char cs=' ', bool wt=false)
    {
    	customerName = n;
		cakeNo = cn;
		quantity = q;
	    pricePerCake = cp;
	    toppingNo = tn;
	    toppingPrice = tp;
		cakeSize = cs;
		withTopping = wt;
		next = nullptr; 
	}
};
// ========================== STRUCTURE FOR DELIVERY ==========================
struct DeliveryNode 
{
    string  houseNo, streetNo, city, deliveryDate, deliveryTime, deliveryDay ;
    double distance;
    DeliveryNode* next;
    DeliveryNode( string hn, string sn, string c, double d, string ddate, string dt, string dday )
    {
    	houseNo = hn;
		streetNo = sn;
		city = c;
	    distance = d;
	    deliveryDate = ddate;
	    deliveryTime = dt;
		deliveryDay = dday;
		next = nullptr; 
	}
};
// ========================== STRUCTURE FOR PAYMENT ==========================
struct PaymentNode 
{
    string name, mobile;
    PaymentNode* next;

    PaymentNode( string n, string m )
    {
    	name = n;
		mobile = m;
		next = nullptr; 
	}
};
// ========================== STRUCTURE FOR FEEDBACK ==========================
struct FeedbackNode 
{
    string customerName, feedback;
    int rating;  
    FeedbackNode* next;

    FeedbackNode( string n, string fb, int r) 
	{
        customerName = n;
        feedback = fb;
        rating = r;
        next = nullptr;
    }
};

// ========================== ADMIN ==========================
// ========================== CLASS FOR ADMIN PROFILE ==========================
class AdminProfile 
{
    private:
    AdminNode* head;

    public:
    AdminProfile()
	{
        head = new AdminNode("admin", "123");
	} 

    bool login( string username, string password ) 
	{
        AdminNode* current = head;
        while( current ) 
		{
            if( current->username==username && current->password==password ) 
			{
				cout<<"__________________________________________________________________________________________\n";
				cout<<"|                                                                                        |\n";
                cout<<"|                 Login successful! Welcome "<<username<<"                                \n";
                cout<<"|________________________________________________________________________________________|\n";
                return true;
            }
            current = current->next;
        }
        cout<<"__________________________________________________________________________________________\n";
		cout<<"|                                                                                        |\n";
        cout<<"|                 Invalid username or password. Please try again.                        |\n";
        cout<<"|________________________________________________________________________________________|\n";
        return false;
    }

    ~AdminProfile() 
	{
        while( head ) 
		{
            AdminNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
// ========================== CLASS FOR CUSTOMER ACCESS ==========================
class CustomerAccess 
{
    private:
    CustomerNode* head; 

    public:
    CustomerAccess()
	{
	    head=nullptr;
	} 

    void addCustomer( int id, string name, string email ) 
	{
        CustomerNode* newNode = new CustomerNode(id, name, email);
        newNode->next = head;
        head = newNode;
    }

    void viewCustomerAccounts() 
	{
        if( !head ) 
		{
			cout<<"__________________________________________________________________________________________\n";
			cout<<"|                                                                                        |\n";
            cout<<"|                          No customer accounts available.                               |\n";
            cout<<"|________________________________________________________________________________________|\n";
            return;
        }
        CustomerNode* current = head;
        while( current ) 
		{
        	cout<<"__________________________________________________________________________________________\n";
			cout<<"|                                                                                        |\n";
			cout<<"|                       _______________________________________                          |\n";
            cout<<"|                       |                                     |                          |\n";
            cout<<"|                       |          CUSTOMER RECORD            |                          |\n";
            cout<<"|                       |_____________________________________|                          |\n";
            cout<<"|                                                                                        |\n";
            cout<<"|                                                                                        |\n";
            cout<<"|                          1.  Customer ID : "<<current->customerId<<"                    \n";
            cout<<"|                                                                                        |\n";
            cout<<"|                          2.  Name : "<<current->name<<"                                 \n";
            cout<<"|                                                                                        |\n";
            cout<<"|                          3.  Email : "<<current->email<<"                               \n";
            cout<<"|                                                                                        |\n";
            cout<<"|                                                                                        |\n";
            cout<<"|________________________________________________________________________________________|\n";
            current = current->next;
        }
    }

    void updateCustomerProfile( int customerId, string newName, string newEmail ) 
	{
        CustomerNode* current = head;
        while( current ) 
		{
            if( current->customerId==customerId ) 
			{
                current->name = newName;
                current->email = newEmail;
                cout<<"__________________________________________________________________________________________\n";
			    cout<<"|                                                                                        |\n";
                cout<<"|                         Customer profile updated successfully!                         |\n";
                cout<<"|________________________________________________________________________________________|\n";
                return;
            }
            else
            {
            	cout<<"__________________________________________________________________________________________\n";
		        cout<<"|                                                                                        |\n";
                cout<<"|                              Customer ID not found !!                                  |\n";
                cout<<"|________________________________________________________________________________________|\n";
			}
            current = current->next;
        }
    }

    void deleteCustomerProfile( int customerId ) 
	{
        CustomerNode* current = head;
        CustomerNode* prev = nullptr;
        // If the customer is the first node
        if( current!=nullptr && current->customerId==customerId ) 
		{
            head = current->next; 
            delete current;
            cout<<"__________________________________________________________________________________________\n";
	    	cout<<"|                                                                                        |\n";
            cout<<"|                          Customer profile deleted successfully!                        |\n";
            cout<<"|________________________________________________________________________________________|\n";
            return;
        }
        // Search for the customer to delete
        while( current!=nullptr && current->customerId!=customerId ) 
		{
            prev = current;
            current = current->next;
        }
        if( current==nullptr ) 
		{
			cout<<"__________________________________________________________________________________________\n";
		    cout<<"|                                                                                        |\n";
            cout<<"|                              Customer ID not found !!                                  |\n";
            cout<<"|________________________________________________________________________________________|\n";
            return;
        }
        // Unlink the node from the linked list
        prev->next = current->next;
        delete current;
        cout<<"__________________________________________________________________________________________\n";
		cout<<"|                                                                                        |\n";
        cout<<"|                          Customer profile deleted successfully!                        |\n";
        cout<<"|________________________________________________________________________________________|\n";
    }

    ~CustomerAccess() 
	{
        while( head ) 
		{
            CustomerNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
// ========================== CLASS FOR CAKE CATALOG ==========================
class CakeCatalog 
{
    private:
    CakeNode* head;

    public:
    CakeCatalog()
	{
		head=nullptr;
	}

    void addCake( string& flavor, string& description, double& price, string& size) 
	{
        CakeNode* newCake = new CakeNode(flavor, description, price, size);
        if( !head ) 
		{
            head = newCake;
        } 
		else 
		{
            CakeNode* temp = head;
            while( temp->next ) 
			{
                temp = temp->next;
            }
            temp->next = newCake;
        }
    }

    CakeNode* findCake( string& flavor ) 
	{
        CakeNode* temp = head;
        while( temp ) 
		{
            if( temp->flavor==flavor ) 
			{
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    void updateCake( string& flavor, string& newFlavor, string& newDescription, double& newPrice, string& newSize ) 
	{
        CakeNode* cake = findCake(flavor);
        if( cake ) 
		{
            cake->flavor = newFlavor;
            cake->description = newDescription;
            cake->price = newPrice;
            cake->size = newSize;
            cout<<"__________________________________________________________________________________________\n";
		    cout<<"|                                                                                        |\n";
            cout<<"|                       Cake flavor  ~ "<<flavor<<" ~  has been updated.                  \n";
            cout<<"|________________________________________________________________________________________|\n";
        } 
		else 
		{
			cout<<"__________________________________________________________________________________________\n";
		    cout<<"|                                                                                        |\n";
            cout<<"|                       Cake flavor  ~ "<<flavor<<" ~  not found in the catalog.          \n";
            cout<<"|________________________________________________________________________________________|\n";
        }
    }

    void removeCake( string& flavor ) 
	{
        CakeNode* temp = head;
        CakeNode* prev = nullptr;

        while( temp&&temp->flavor!=flavor ) 
		{
            prev = temp;
            temp = temp->next;
        }
        if( !temp ) 
		{
            cout<<"__________________________________________________________________________________________\n";
		    cout<<"|                                                                                        |\n";
            cout<<"|                       Cake flavor  ~ "<<flavor<<" ~  not found in the catalog.          \n";
            cout<<"|________________________________________________________________________________________|\n";
            return;
        }
        if( !prev ) 
		{
            head = temp->next; // Removing the head
        } 
		else 
		{
            prev->next = temp->next;
        }
        delete temp;
        cout<<"__________________________________________________________________________________________\n";
		cout<<"|                                                                                        |\n";
        cout<<"|                  Cake flavor  ~ "<<flavor<<" ~  has been removed from catalog.          \n";
        cout<<"|________________________________________________________________________________________|\n";
    }

    void displayCakes() 
	{
        if( !head ) 
		{
			cout<<"__________________________________________________________________________________________\n";
		    cout<<"|                                                                                        |\n";
            cout<<"|                                 The cake catalog is empty!                             |\n";
            cout<<"|________________________________________________________________________________________|\n";
            return;
        }
        cout<<"__________________________________________________________________________________________\n";
        cout<<"|                                                                                        |\n";
        cout<<"|                       _______________________________________                          |\n";
        cout<<"|                       |                                     |                          |\n";
        cout<<"|                       |               CAKE  MENU            |                          |\n";
        cout<<"|                       |_____________________________________|                          |\n";
        cout<<"|                                                                                        |\n";
        CakeNode* temp = head;
        while( temp ) 
		{
			cout<<"|                                                                                        |\n";
            cout<<"|               Flavor : "<<temp->flavor<<"                                               \n";
			cout<<"|               Description : "<<temp->description<<"                                     \n";
            cout<<"|               Price : $."<<temp->price<<"                                               \n";
			cout<<"|	           Size : "<<temp->size<<"                                                   \n";
			cout<<"|                                                                                        |\n";
            temp = temp->next;
        }
        cout<<"|                                                                                        |\n";
        cout<<"|________________________________________________________________________________________|\n";
    }

    ~CakeCatalog() 
	{
        while( head ) 
		{
            CakeNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
// ========================== CLASS FOR MANAGING ORDER ==========================
class OrderManagement 
{
    private:
    OrderNode* head;

    public:
    OrderManagement()
	{
		head=nullptr;
	}

    void addOrder( int orderId, int customerId, string status ) 
	{
        OrderNode* newNode = new OrderNode(orderId, customerId, status);
        newNode->next = head;
        head = newNode;
        cout<<"__________________________________________________________________________________________\n";
        cout<<"|                                                                                        |\n";
        cout<<"|                               Order added successfully !!                              |\n";
        cout<<"|________________________________________________________________________________________|\n";
    }

    void trackOrders() 
	{
        if( !head ) 
		{
            cout<<"__________________________________________________________________________________________\n";
            cout<<"|                                                                                        |\n";
            cout<<"|                                No Orders available !!                                  |\n";
            cout<<"|________________________________________________________________________________________|\n";
            return;
        }
        OrderNode* current = head;
        int orderCount = 0;  
        while( current ) 
		{
            orderCount++;
            cout<<"__________________________________________________________________________________________\n";
            cout<<"|                                                                                        |\n";
            cout<<"|                       _______________________________________                          |\n";
            cout<<"|                       |                                     |                          |\n";
            cout<<"|                       |             TRACK ORDER             |                          |\n";
            cout<<"|                       |_____________________________________|                          |\n";
            cout<<"|                                                                                        |\n";
            cout<<"|                                                                                        |\n";
            cout<<"|                              Order ID : "<<current->orderId<<"                          \n";
            cout<<"|                                                                                        |\n";
            cout<<"|                              Customer ID : "<<current->customerId<<"                    \n";
            cout<<"|                                                                                        |\n";
            cout<<"|                              Order Status : " <<current->orderStatus<<"                 \n";
            cout<<"|                                                                                        |\n";
            cout<<"|________________________________________________________________________________________|\n";
            current = current->next;
        }
        if( orderCount==0 ) 
		{
            cout<<"__________________________________________________________________________________________\n";
            cout<<"|                                                                                        |\n";
            cout<<"|                               No Orders to display !!                                  |\n";
            cout<<"|________________________________________________________________________________________|\n";
        }
    }

    void updateOrderStatus( int orderId, string newStatus ) 
	{
        OrderNode* current = head;
        while( current ) 
		{
            if( current->orderId==orderId ) 
			{
                current->orderStatus = newStatus;
                cout<<"__________________________________________________________________________________________\n";
                cout<<"|                                                                                        |\n";
                cout<<"|                 Order ID : "<<orderId<<" status updated to "<<newStatus<<" .            \n";
                cout<<"|________________________________________________________________________________________|\n";
                return;
            }
            current = current->next;
        }
        cout<<"__________________________________________________________________________________________\n";
        cout<<"|                                                                                        |\n";
        cout<<"|                                 Order ID not found !!                                  |\n";
        cout<<"|________________________________________________________________________________________|\n";
    }

    void cancelOrder( int orderId ) 
	{
        OrderNode* current = head;
        OrderNode* prev = nullptr;
        if( current!=nullptr && current->orderId==orderId ) 
		{
            head = current->next; 
            delete current;
            cout<<"__________________________________________________________________________________________\n";
            cout<<"|                                                                                        |\n";
            cout<<"|                           Order ID : "<<orderId<<" has been cancelled.                  \n";
            cout<<"|________________________________________________________________________________________|\n";
            return;
        }
        // Search for the order to cancel
        while( current!=nullptr && current->orderId!=orderId ) 
		{
            prev = current;
            current = current->next;
        }
        if( current == nullptr ) 
		{
            cout<<"__________________________________________________________________________________________\n";
            cout<<"|                                                                                        |\n";
            cout<<"|                                 Order ID not found !!                                  |\n";
            cout<<"|________________________________________________________________________________________|\n";
            return;
        }
        // Unlink the node from the linked list
        prev->next = current->next;
        delete current;
        cout<<"__________________________________________________________________________________________\n";
        cout<<"|                                                                                        |\n";
        cout<<"|                           Order ID : "<<orderId<<" has been cancelled.                  \n";
        cout<<"|________________________________________________________________________________________|\n";
    }

    ~OrderManagement() 
	{
        while( head ) 
		{
            OrderNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

void addCake( cakeNode*& head, int id, string name, double price ) 
{
    cakeNode* newCake = new cakeNode{id, name, price, 0.0, nullptr};
    if( !head ) 
	{
        head = newCake;
    } 
	else 
	{
        cakeNode* temp = head;
        while( temp->next ) 
		{
            temp = temp->next;
        }
        temp->next = newCake;
    }
}

void displayMenu( cakeNode* head ) 
{
    if( !head ) 
	{
        cout<<"__________________________________________________________________________________________\n";
        cout<<"|                                                                                        |\n";
        cout<<"|                              The Menu is currently empty !                             |\n";
        cout<<"|________________________________________________________________________________________|\n";
        return;
    }
    cout<<"__________________________________________________________________________________________\n";
    cout<<"|                                                                                        |\n";
    cout<<"|                       _______________________________________                          |\n";
    cout<<"|                       |                                     |                          |\n";
    cout<<"|                       |               CAKE  MENU            |                          |\n";
    cout<<"|                       |_____________________________________|                          |\n";
    cout<<"|                                                                                        |\n";
    cakeNode* temp = head;
    while( temp ) 
	{
		cout<<"|                                                                                        |\n";
        cout<<"|               ID : "<<temp->id<<"                                                       \n";
		cout<<"|               Name : "<<temp->name<<"                                                   \n";
        cout<<"|               Price : $."<<temp->price<<"                                               \n";
		cout<<"|	           Discount : "<<temp->discount<<" %.                                        \n";
		cout<<"|                                                                                        |\n";
        temp = temp->next;        
    }
    cout<<"|                                                                                        |\n";
    cout<<"|________________________________________________________________________________________|\n";
}

void applyDiscount( cakeNode* head, int id, double discount ) 
{
    cakeNode* temp = head;
    while( temp ) 
	{
        if( temp->id == id ) 
		{
            temp->discount = discount;
            cout<<"__________________________________________________________________________________________\n";
            cout<<"|                                                                                        |\n";
            cout<<"|                Discount applied successfully to : "<<temp->name<<"                      \n";
            cout<<"|________________________________________________________________________________________|\n";
            return;
        }
        temp = temp->next;
    }
    cout<<"__________________________________________________________________________________________\n";
    cout<<"|                                                                                        |\n";
    cout<<"|                           Cake with ID : "<<id<<" not found !                          |\n";
    cout<<"|________________________________________________________________________________________|\n";
}

void checkout(cakeNode* head) 
{
    if( !head ) 
	{
		cout<<"__________________________________________________________________________________________\n";
        cout<<"|                                                                                        |\n";
        cout<<"|                            No cakes available for checkout                             |\n";
        cout<<"|________________________________________________________________________________________|\n";
        return;
    }
    double totalCost = 0;
    double discountAmount = 0;
    int numCakes = 0;
    cout<<"__________________________________________________________________________________________\n";
    cout<<"|                                                                                        |\n";
    cout<<"|          Enter the IDs of the cakes you want to purchase (Enter -1 to finish) :        |\n";
    cout<<"|________________________________________________________________________________________|\n";
    while( true ) 
	{
        int id;
        cin>>id;
        if( id == -1) break;
        cakeNode* temp = head;
        while( temp ) 
		{
            if( temp->id==id) 
			{
                double finalPrice = temp->price * (1 - temp->discount / 100.0);
                totalCost += finalPrice;
                numCakes++;
                break;
            }
            temp = temp->next;
        }
    }

    if( numCakes>=2 ) 
	{
        discountAmount = totalCost * 0.1; // 10% discount
        totalCost -= discountAmount; // Subtract the discount from total cost
        cout<<"__________________________________________________________________________________________\n";
        cout<<"|                                                                                        |\n";
        cout<<"|            You have received a 10% discount for purchasing 2 or more cakes!            |\n";
        cout<<"|________________________________________________________________________________________|\n";
    } 
	else if( numCakes == 1 ) 
	{
		cout<<"__________________________________________________________________________________________\n";
        cout<<"|                                                                                        |\n";
        cout<<"|                  Congratulations! You have been awarded a gift of pastry !             |\n";
        cout<<"|________________________________________________________________________________________|\n";
    }
    cout<<"__________________________________________________________________________________________\n";
    cout<<"|                                                                                        |\n";
    cout<<"|                  Total Price (before discount) : $"<<fixed<<(totalCost+discountAmount)<<"\n";
    cout<<"|                                                                                        |\n";
    cout<<"|                  Discount Amount : $" <<fixed <<discountAmount<<"                       \n";
    cout<<"|                                                                                        |\n";
    cout<<"|                  Total Payment after Discount : $"<<fixed<<totalCost<<"                 \n";
    cout<<"|                                                                                        |\n";
    cout<<"|________________________________________________________________________________________|\n";   
}
// ========================== CLASS FOR DELIVERY ==========================
class DeliveryControl 
{
    private:
    DeliveryControlNode* head;

    public:
    DeliveryControl()
	{
		head=nullptr;
	}

    void addPersonnel( int personnelId, string name, string status ) 
	{
        DeliveryControlNode* newNode = new DeliveryControlNode(personnelId, name, status);
        newNode->next = head;
        head = newNode;
        cout<<"__________________________________________________________________________________________\n";
        cout<<"|                                                                                        |\n";
        cout<<"|                           Delivery personnel added successfully!                       |\n";
        cout<<"|________________________________________________________________________________________|\n";
    }

    void updateStatus( int personnelId, string newStatus ) 
	{
        DeliveryControlNode* current = head;
        while( current ) 
		{
            if( current->personnelId==personnelId ) 
			{
                current->status = newStatus;
                cout<<"__________________________________________________________________________________________\n";
                cout<<"|                                                                                        |\n";
                cout<<"|             Status updated successfully for Personnel ID : "<<personnelId<<"            \n";
                cout<<"|________________________________________________________________________________________|\n";
                return;
            }
            current = current->next;
        }
        cout<<"__________________________________________________________________________________________\n";
        cout<<"|                                                                                        |\n";
        cout<<"|                                  Personnel ID not found.                               |\n";
        cout<<"|________________________________________________________________________________________|\n";
    }

    void viewPersonnel() 
	{
        if( !head ) 
		{
        	cout<<"__________________________________________________________________________________________\n";
            cout<<"|                                                                                        |\n";
            cout<<"|                              No delivery personnel available.                          |\n";
            cout<<"|________________________________________________________________________________________|\n";
            return;
        }
        DeliveryControlNode* current = head;
        while( current ) 
		{
			cout<<"__________________________________________________________________________________________\n";
            cout<<"|                                                                                        |\n";
            cout<<"|                       _______________________________________                          |\n";
            cout<<"|                       |                                     |                          |\n";
            cout<<"|                       |        DELIVERY PERSONAL LIST       |                          |\n";
            cout<<"|                       |_____________________________________|                          |\n";
            cout<<"|                                                                                        |\n";
            cout<<"|                                                                                        |\n";
            cout<<"|                            Personnel ID : "<<current->personnelId<<"                    \n";
            cout<<"|                                                                                        |\n";
            cout<<"|                            Name : "<<current->name<<"                                   \n";
            cout<<"|                                                                                        |\n";
            cout<<"|                            Status : "<<current->status<<"                               \n";
            cout<<"|                                                                                        |\n";
            cout<<"|                                                                                        |\n";
            cout<<"|________________________________________________________________________________________|\n";
            current = current->next;
        }
    }

    ~DeliveryControl() 
	{
        while( head ) 
		{
            DeliveryControlNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
// ========================== CLASS FOR FINANCIAL ==========================
class Financial 
{
    private:
    vector<financial> f; 
    double totalSales;

    public:
    Financial() 
	{
	    totalSales=0.0;	
	}

    void addOrder( const string& flavor, const string& size, int quantity, double price ) 
	{
        financial newOrder = {flavor, size, quantity, price * quantity};
        f.push_back(newOrder);
        totalSales += newOrder.totalPrice;
    }

    void generateSalesReport( double singleCakePrice ) const 
	{
        double threeCakesCost = singleCakePrice * 3;
        cout<<"__________________________________________________________________________________________\n";
		cout<<"|                                                                                        |\n";
		cout<<"|                       _______________________________________                          |\n";
        cout<<"|                       |                                     |                          |\n";
        cout<<"|                       |          FINANCIAL REPORT           |                          |\n";
        cout<<"|                       |_____________________________________|                          |\n";
        cout<<"|                                                                                        |\n";
        cout<<"|                                                                                        |\n";
        cout<<"|                             Total Sales Today : $"<<totalSales<<"                       \n";
		cout<<"|                                                                                        |\n";
		cout<<"|                             Cost of 3 Cakes : $"<<threeCakesCost<<"                     \n";
        cout<<"|                                                                                        |\n";
        if( totalSales>threeCakesCost ) 
		{
            cout<<"|                          Profit : $ "<<(totalSales - threeCakesCost)<<"                 \n";
        } 
		else if( totalSales<threeCakesCost ) 
		{
            cout<<"|                          Loss : $ "<<(threeCakesCost - totalSales)<<"                   \n";
        } 
		else 
		{
            cout<<"|                                  No Profit, No Loss.                                   |\n";
        }
        cout<<"|                                                                                        |\n"; 
        cout<<"|________________________________________________________________________________________|\n";
    }
};

// ========================== CUSTOMER ==========================
// ========================== CLASS FOR CUSTOMER PROFILE ==========================
class CustomerProfile 
{
    private:
    CustomerNodes* head;

    public:
    CustomerProfile() 
	{
		head=nullptr;	
	}

    void signUp( string name, string email, string mobile, string username, string password) 
	{
        CustomerNodes* current = head;
        while( current ) 
		{
            if( current->username==username) 
			{
				cout<<"__________________________________________________________________________________________\n";
				cout<<"|                                                                                        |\n";
                cout<<"|         Username already exists. Please choose a different username.                   |\n";
                cout<<"|________________________________________________________________________________________|\n";
                return;
            }
            current=current->next;
        }
        CustomerNodes* nn = new CustomerNodes(name, email, mobile, username, password);
        nn->next=head;
        head=nn;
        cout<<"___________________________________________________________________________\n";
		cout<<"|                                                                         |\n";
        cout<<"|                  Customer signed up successfully!!                      |\n";
        cout<<"|_________________________________________________________________________|\n";
    }

    bool login(string un, string pw) 
	{
        CustomerNodes* current = head;
        while( current ) 
		{
            if( current->username==un && current->password==pw) 
			{
				cout<<"___________________________________________________________________________\n";
	        	cout<<"|                                                                         |\n";
                cout<<"|               Login successful! Welcome, "<<un<<" !                      \n";
                cout<<"|_________________________________________________________________________|\n";
                return true;
            }
            current=current->next;
        }
        cout<<"___________________________________________________________________________\n";
	    cout<<"|                                                                         |\n";
		cout<<"|             Invalid username or password. Please try again.             |\n";
		cout<<"|_________________________________________________________________________|\n";
        return false;
    }

    ~CustomerProfile() 
	{
        while (head) 
		{
            CustomerNodes* temp = head;
            head=head->next;
            delete temp;
        }
    }
};
// ========================== CLASS FOR ORDER MANAGEMENT ==========================
class OrderManagements 
{
    private:
    OrderNodes* head;

    public:
    OrderManagements() 
	{
		head = nullptr;
	} 

    void placeOrder()  
	{
		string customerName;
        int cakeNo, quantity, toppingNo = 0;
        char cakeSize, cakeTopping;
        int pricePerCake, toppingPrice = 0;
        bool withTopping = false;
        cout<<"___________________________________________________________________________________\n";
        cout<<"|                                                                                 |\n";
        cout<<"|                    ______________________________________                       |\n";
        cout<<"|                    |                                    |                       |\n";
        cout<<"|                    |              PLACE ORDER           |                       |\n";
        cout<<"|                    |____________________________________|                       |\n";
        cout<<"|                                                                                 |\n";
        cout<<"|                                                                                 |\n";
        cout<<"|                            Enter your name : "; 
        cin.ignore();
        getline(cin, customerName);
        cout<<"|                                                                                 |\n";
        cout<<"|                            Enter the cake no. ( 1-10 ): ";
        cin>>cakeNo;
        if( cakeNo<1 || cakeNo>10 ) 
		{
                cout<<"Invalid cake selection! Please choose a valid cake number \n";
                return ;
        }
        cout<<"|                                                                                 |\n";
        cout<<"|                            Enter the cake size ( s/m/l ) : ";
        cin>>cakeSize;
        if( cakeSize!='s' && cakeSize!='m' && cakeSize!='l' ) 
		{
            cout<<"Invalid cake size selection !! \n";
            return ;
        }
        cout<<"|                                                                                 |\n";
        cout<<"|                            Enter the Quantity : ";
        cin>>quantity;
        cout<<"|                                                                                 |\n";
        
		cout<<"|_________________________________________________________________________________|\n";
    cout<<"__________________________________________________________________________________________\n";
    cout<<"|                                                                                        |\n";
    cout<<"|                       _______________________________________                          |\n";
    cout<<"|                       |                                     |                          |\n";
    cout<<"|                       |           EXTRA TOPPINGS            |                          |\n";
    cout<<"|                       |_____________________________________|                          |\n";
    cout<<"|                                                                                        |\n";
    cout<<"|                                                                                        |\n";
    cout<<"|                      NO.        TOPPING-NAME             PRICE                         |\n";
    cout<<"|                                                                                        |\n";
    cout<<"|                      1.           Sprinkles               150                          |\n";
    cout<<"|                      2.         Whipped Cream             150                          |\n";
    cout<<"|                      3.        Chocolate Chips            150                          |\n";
    cout<<"|                                                                                        |\n";
    cout<<"|________________________________________________________________________________________|\n";   
		cout<<"___________________________________________________________________________________\n";
        cout<<"|                                                                                 |\n";
        cout<<"|                            Do you want extra Toppings ( y/n ) : ";
        cin>>cakeTopping;
		if( cakeTopping=='y' )
		{
			cout<<"|                                                                                 |\n";
            cout<<"|                            Enter the topping no. : ";
            cin>>toppingNo;
            if( toppingNo<1 || toppingNo>3 ) 
			{
                cout<<"Invalid topping no. selection !! \n";
                return ;
            }
	    } 
        OrderNodes* nn = new OrderNodes(customerName, cakeNo, cakeSize, quantity, pricePerCake, withTopping, toppingNo, toppingPrice);
        if( !head )
        {
        	head=nn;
		}
		else
		{
			OrderNodes* temp = head;
			while( temp->next ) 
		    {
                temp=temp->next;
            }
            temp->next = nn;
		}
		cout<<"|                 ________________________________________________                |\n";
        cout<<"|                 |                                              |                |\n";
        cout<<"|                 |          YOUR ORDER HAS BEEN PLACED          |                |\n";
        cout<<"|                 |______________________________________________|                |\n";
        cout<<"|                                                                                 |\n";
        cout<<"|_________________________________________________________________________________|\n";
    }

    void displayTrackOrder() 
	{
		if( !head )
		{
            cout<<"___________________________________________________________________________\n";
	        cout<<"|                                                                         |\n";
            cout<<"|                               No Orders found !                         |\n";
            cout<<"|_________________________________________________________________________|\n";
            return ;
	    }
	    string customerName;
        cout<<"_________________________________________________________________________________\n";
        cout<<"|                                                                               |\n";
        cout<<"|              Enter your name to Track Order: ";
        cin.ignore();
        getline(cin, customerName);
        cout<<"|_______________________________________________________________________________|\n";
        OrderNodes* current = head;
        bool found = false;
        while( current ) 
		{
            string cakeDescription;
            switch( current->cakeNo ) 
			{
                case 1: cakeDescription = "A rich chocolate cake with creamy filling..."; break;
                case 2: cakeDescription = "A light and fluffy vanilla cake..."; break;
                case 3: cakeDescription = "A moist red velvet cake with cream cheese frosting..."; break;
                case 4: cakeDescription = "A soft cake made with fresh strawberries..."; break;
                case 5: cakeDescription = "A smooth cake with rich cream topping..."; break;
                case 6: cakeDescription = "A sweet and tangy pineapple cake..."; break;
                case 7: cakeDescription = "A moist cake with a rich coffee flavor..."; break;
                case 8: cakeDescription = "A creamy and rich cheesecake..."; break;
                case 9: cakeDescription = "A buttery, soft cake..."; break;
                case 10: cakeDescription = "A cake filled with fresh seasonal fruits..."; break;
                default: cakeDescription = "Unknown cake."; break;
            }    
        if( current->customerName==customerName )
        {
            // Display order details
            cout<<"__________________________________________________________________________________________\n";
            cout<<"|                                                                                        |\n";
            cout<<"|                       _______________________________________                          |\n";
            cout<<"|                       |                                     |                          |\n";
            cout<<"|                       |             TRACK ORDER             |                          |\n";
            cout<<"|                       |_____________________________________|                          |\n";
            cout<<"|                                                                                        |\n";
            cout<<"|                     Your name : "<<current->customerName<<"                             \n";
            cout<<"|                     Your selected cake : "<<current->cakeNo<<"                          \n";
            cout<<"|                                                                                        |\n";
            cout<<"|                  ~~ "<<cakeDescription<<" ~~                                            \n";
            cout<<"|                                                                                        |\n";
			cout<<"|                     Your selected cake size : "<<current->cakeSize<<"                   \n";
            cout<<"|                     Price of 1 cake : "<<current->pricePerCake<<"                       \n";
            cout<<"|                     Your selected quantity : "<<current->quantity<<"                    \n";
            cout<<"|                                                                                        |\n";
            if( current->withTopping ) 
			{
                cout<<"|                     Selected topping : "<<current->toppingNo<<"                         \n";
                cout<<"|                     Topping price : "<< current->toppingPrice<<"                        \n";
                cout<<"|                                                                                        |\n";
            }
            cout<<"|                     Total Price : "<<(current->pricePerCake*current->quantity+(current->withTopping?current->toppingPrice:0))<<" \n";
            cout<<"|________________________________________________________________________________________|\n\n";
            char cancelOrderChoice;
            cout<<"____________________________________________________________________________________\n";
            cout<<"|                                                                                  |\n";
            cout<<"|               Do you want to cancel your order ( y/n ) : ";
            cin>>cancelOrderChoice;
            if( cancelOrderChoice=='y' ) 
			{
                cout<<"|                                                                                  |\n";
                cout<<"|                            ORDER HAS BEEN CANCELED                               |\n";
                cout<<"|                                                                                  |\n";
                cout<<"|__________________________________________________________________________________|\n";
            } 
			else 
			{
                cout<<"|                                                                                  |\n";
                cout<<"|                            ORDER HAS BEEN PLACED                                 |\n";
                cout<<"|                                                                                  |\n";
                cout<<"|__________________________________________________________________________________|\n";
            }
            found=true;
            break;
          }
        current=current->next;
		}
		if( !found )
		{
            cout<<"___________________________________________________________________________\n";
	        cout<<"|                                                                         |\n";
            cout<<"|                  No Orders found for "<<customerName<<"!                 \n";
            cout<<"|_________________________________________________________________________|\n";
	    }
    }

    ~OrderManagements() 
	{
        while( head ) 
		{
            OrderNodes* temp = head;
            head=head->next;
            delete temp;
        }
    }
};
// ========================== CLASS FOR TRACKING DELIVERY ==========================
class DeliveryTracker 
{
    private:
    DeliveryNode* head;

    public:
    DeliveryTracker() 
	{
        head = nullptr;
    }

    void addDelivery( string houseNo, string streetNo, string city, int distance, string deliveryDate, string deliveryTime, string deliveryDay ) 
	{
        DeliveryNode* nn = new DeliveryNode( houseNo, streetNo, city, distance, deliveryDate, deliveryTime, deliveryDay );
        nn->next = head;
        head = nn;
    }

    void displayTrackDelivery() 
	{
        DeliveryNode* current = head;
        int distance;
        string houseNo, streetNo, city, deliveryDate, deliveryTime, deliveryDay;
        cout<<"____________________________________________________________________________________________________\n";
        cout<<"|                                                                                                  |\n";
        cout<<"|                              _______________________________________                             |\n";
        cout<<"|                              |                                     |                             |\n";
        cout<<"|                              |             TRACK DELIVERY          |                             |\n";
        cout<<"|                              |_____________________________________|                             |\n";
        cout<<"|                                                                                                  |\n";
        cout<<"|                                                                                                  |\n";
        cout<<"|                            Enter your house no : ";
        cin.ignore();
		getline( cin,houseNo );
        cout<<"|                            Enter your street no : ";
        getline( cin,streetNo );
        cout<<"|                            Enter your city : ";  
        getline( cin,city);
        cout<<"|                            Enter your distance in km : ";
        cin>>distance;
        cin.ignore();
        cout<<"|                            Enter your preferred delivery date ( dd/mm/yyyy ) : ";
        getline( cin,deliveryDate );
        cout<<"|                            Enter your preferred delivery time ( HH:MM ) : ";
        getline( cin,deliveryTime );
        cout<<"|                            Enter your preferred delivery day : ";
        getline( cin,deliveryDay );
        cout<<"|                                                                                                  |\n";
        cout<<"|                                                                                                  |\n";
        cout<<"|                       __________________________________________________                         |\n";
        cout<<"|                       |                                                |                         |\n";
        cout<<"|                       |          YOUR DELIVERY IS ON THE WAY !!        |                         |\n";
        cout<<"|                       |________________________________________________|                         |\n";
        cout<<"|                                                                                                  |\n";
        cout<<"|                                                                                                  |\n";
        cout<<"|              Delivery will take place on "<<deliveryDay<<", "<<deliveryDate<<" at "<<deliveryTime<<"    \n";
        cout<<"|                                                                                                  |\n";
        cout<<"|__________________________________________________________________________________________________|\n";
    }

    ~DeliveryTracker() 
	{
        while( head ) 
		{
            DeliveryNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
// ========================== CLASS FOR PAYMENT ==========================
class PaymentList
{
    private:
    PaymentNode* head;

    public:
    PaymentList() 
	{
		head=nullptr;	
	}

    void paymentOption( string name, string mobile ) 
	{
        
        PaymentNode* nn = new PaymentNode( name, mobile );
        nn->next = head;
        head = nn;
    }

    ~PaymentList() 
	{
        while( head ) 
		{
            PaymentNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
// ========================== CLASS FOR FEEDBACK AND RATINGS ==========================
class FeedbackList 
{
    private:
    FeedbackNode* head;  

    public:
    FeedbackList() 
	{
        head = nullptr;
    }

    void addFeedback( string name, string feedback, int rating ) 
	{
        FeedbackNode* nn = new FeedbackNode( name, feedback, rating );
        nn->next = head;
        head = nn;
    }

    ~FeedbackList() 
	{
        while( head ) 
		{
            FeedbackNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Functions.........
// Function to display the Cake Master Management System title
void displayTitle() 
{
	system("cls");
    cout<<"__________________________________________________________________________________________\n";
    cout<<"|                                                                                        |\n";
    cout<<"|                   _____       _____ ______            _____      _______  ______       |\n";
    cout<<"|        |   /.   | |     |     |     |    | |.      /| |             |     |    |       |\n";
    cout<<"|        |  /  .  | |____ |     |     |    | | .    / | |____         |     |    |       |\n";
    cout<<"|        | /    . | |     |     |     |    | |  .  /  | |             |     |    |       |\n";
    cout<<"|        |/      .| |____ |____ |____ |____| |   ./   | |____         |     |____|       |\n";
    cout<<"|                                                                                        |\n";
    cout<<"|                                                                                        |\n";
    cout<<"|                     ________________________________________________                   |\n";
    cout<<"|                     |                                              |                   |\n";
    cout<<"|                     |      CAKE MASTER MANAGEMENT SYSTEM           |                   |\n";
    cout<<"|                     |______________________________________________|                   |\n";
    cout<<"|                                                                                        |\n";
    cout<<"|                                                                                        |\n";
    cout<<"|                                                                                        |\n";
    cout<<"|                                  YOU WANT TO LOG-IN AS                                 |\n";
    cout<<"|                                                                                        |\n";
    cout<<"|                                                                                        |\n";
    cout<<"|             ______________________                    ______________________           |\n";
    cout<<"|             |                    |                    |                    |           |\n";
    cout<<"|             |        ADMIN       |                    |     CUSTOMER       |           |\n";
    cout<<"|             |____________________|                    |____________________|           |\n";
    cout<<"|                                                                                        |\n";
    cout<<"|________________________________________________________________________________________|\n";
    cout<<"\n\t Press 1 for Admin and 2 for Customer : ";
}
// Function to display Customer options
void displayCustomerOptions() 
{
    cout<<"__________________________________________________________________________________________\n";
    cout<<"|                                                                                        |\n";
    cout<<"|                ________________________________________________                        |\n";
    cout<<"|                |                                              |                        |\n";
    cout<<"|                |           AS A CUSTOMER, YOU WANT TO         |                        |\n";
    cout<<"|                |______________________________________________|                        |\n";
    cout<<"|                                                                                        |\n";
    cout<<"|                              _______________________                                   |\n";
    cout<<"|                              |                     |                                   |\n";
    cout<<"|                              |      SIGN - UP      |                                   |\n";
    cout<<"|                              |_____________________|                                   |\n";
    cout<<"|                                                                                        |\n";
    cout<<"|                              _______________________                                   |\n";
    cout<<"|                              |                     |                                   |\n";
    cout<<"|                              |       LOG - IN      |                                   |\n";
    cout<<"|                              |_____________________|                                   |\n";
    cout<<"|                                                                                        |\n";
    cout<<"|                              _______________________                                   |\n";
    cout<<"|                              |                     |                                   |\n";
    cout<<"|                              |         EXIT        |                                   |\n";
    cout<<"|                              |_____________________|                                   |\n";
    cout<<"|                                                                                        |\n";
    cout<<"|________________________________________________________________________________________|\n";
    cout<<"\n\t Press 1 for Sign-up , 2 for Log-in and 3 for Exit : ";
}
// Function to display the Customer Modules menu
void displayCustomerModules() 
{
    cout<<"__________________________________________________________________________________________\n";
    cout<<"|                                                                                        |\n";
    cout<<"|                       _______________________________________                          |\n";
    cout<<"|                       |                                     |                          |\n";
    cout<<"|                       |          MODULES FOR CUSTOMER       |                          |\n";
    cout<<"|                       |_____________________________________|                          |\n";
    cout<<"|                                                                                        |\n";
    cout<<"|                                                                                        |\n";
    cout<<"|                                1.   Browse Cake.                                       |\n";
    cout<<"|                                2.   Place order.                                       |\n";
    cout<<"|                                3.   Track order.                                       |\n";
    cout<<"|                                4.   Track delivery.                                    |\n";
    cout<<"|                                5.   Payment Option.                                    |\n";
    cout<<"|                                6.   Feedback and rating.                               |\n";
    cout<<"|                                7.   Exit.                                              |\n";
    cout<<"|                                                                                        |\n";
    cout<<"|________________________________________________________________________________________|\n";
    cout<<"\n\t Enter your choice : ";
}
// Function to display the Browse Cake menu
void displayBrowseCake() 
{
    cout<<"__________________________________________________________________________________________\n";
    cout<<"|                                                                                        |\n";
    cout<<"|                       _______________________________________                          |\n";
    cout<<"|                       |                                     |                          |\n";
    cout<<"|                       |             BROWSE CAKES            |                          |\n";
    cout<<"|                       |_____________________________________|                          |\n";
    cout<<"|                                                                                        |\n";
    cout<<"|                                                                                        |\n";
    cout<<"|              NO.        CAKE-NAME             SMALL      MEDIUM     LARGE              |\n";
    cout<<"|                                                                                        |\n";
    cout<<"|              1.       Chocolate Cake           550        1100       2000              |\n";
    cout<<"|              2.       Vanilla Cake             550        1100       2000              |\n";
    cout<<"|              3.       Red Velvet Cake          550        1100       2000              |\n";
    cout<<"|              4.       Strawberry Cake          550        1100       2000              |\n";
    cout<<"|              5.       Cream Cake               550        1100       2000              |\n";
    cout<<"|              6.       Pineapple Cake           550        1100       2000              |\n";
    cout<<"|              7.       Coffee Cake              550        1100       2000              |\n";
    cout<<"|              8.       Cheese Cake              550        1100       2000              |\n";
    cout<<"|              9.       Butter Cake              550        1100       2000              |\n";
    cout<<"|             10.       Fruit Cake               550        1100       2000              |\n";
    cout<<"|                                                                                        |\n";
    cout<<"|________________________________________________________________________________________|\n";
}
// Function to display the Payment Options
void DisplayPaymentOptions()
{
	cout<<"____________________________________________________________________________________\n";
    cout<<"|                                                                                  |\n";
    cout<<"|                       _______________________________________                    |\n";
    cout<<"|                       |                                     |                    |\n";
    cout<<"|                       |           PAYMENT OPTIONS           |                    |\n";
    cout<<"|                       |_____________________________________|                    |\n";
    cout<<"|                                                                                  |\n";
    cout<<"|                                                                                  |\n";
    cout<<"|                         NO.         OPTION-NAME                                  |\n";
    cout<<"|                                                                                  |\n";
    cout<<"|                         1.           Online Payment.                             |\n";
    cout<<"|                         2.           Cash on delivery.                           |\n";
    cout<<"|                                                                                  |\n";
    cout<<"|                                                                                  |\n";
    cout<<"|               Select the payment option ( 1 / 2) : ";
}

// the main function
int main() 
{
	// Admin
	CakeCatalog catalog;
	DeliveryControl control;
	OrderManagement orderManagement;
	CustomerAccess customerAccess;
	Financial F;
	// Customer
	CustomerProfile CP;
    OrderManagements OM;
    DeliveryTracker DT;
    PaymentList PL;
    FeedbackList FL;

    int Choice;
    while( true ) 
	{
		CMS_Title:
        displayTitle(); // Display the CMS title
        cin>>Choice;
        switch( Choice ) 
	    {
	    	// Admin Functionallities
            case 1:
   	        int userType;
            do 
	        {
		    int customerId;
		    string name, status;
		    AM_TITLE:
            system("cls");
		    cout<<"__________________________________________________________________________________________\n";
            cout<<"|                                                                                        |\n";
            cout<<"|                       _______________________________________                          |\n";
            cout<<"|                       |                                     |                          |\n";
            cout<<"|                       |           MODULES FOR ADMIN         |                          |\n";
            cout<<"|                       |_____________________________________|                          |\n";
            cout<<"|                                                                                        |\n";
            cout<<"|                                                                                        |\n";
            cout<<"|                                1.   Admin Profile.                                     |\n";
            cout<<"|                                2.   Customer Access.                                   |\n";
            cout<<"|                                3.   Cake Catalog.                                      |\n";
            cout<<"|                                4.   Order Management.                                  |\n";
            cout<<"|                                5.   cake discount.                                     |\n";
            cout<<"|                                6.   Delivery Control.                                  |\n";
            cout<<"|                                7.   Financial report.                                  |\n";
            cout<<"|                                8.   Exit.                                              |\n";
            cout<<"|                                                                                        |\n";
            cout<<"|________________________________________________________________________________________|\n";  
            cout<<"\n\tEnter your choice: ";
            cin>>userType;
            switch( userType ) 
		    {
                case 1 : 
			    {
                int adminChoice;
                do 
				{
                system("cls"); 
                cout<<"__________________________________________________________________________________________\n";
                cout<<"|                                                                                        |\n";
                cout<<"|                ________________________________________________                        |\n";
                cout<<"|                |                                              |                        |\n";
                cout<<"|                |            AS AN ADMIN, YOU WANT TO          |                        |\n";
                cout<<"|                |______________________________________________|                        |\n";
                cout<<"|                                                                                        |\n";
                cout<<"|                              _______________________                                   |\n";
                cout<<"|                              |                     |                                   |\n";
                cout<<"|                              |    1.  LOG - IN     |                                   |\n";
                cout<<"|                              |_____________________|                                   |\n";
                cout<<"|                                                                                        |\n";
                cout<<"|                              _______________________                                   |\n";
                cout<<"|                              |                     |                                   |\n";
                cout<<"|                              |    2.  EXIT         |                                   |\n";
                cout<<"|                              |_____________________|                                   |\n";
                cout<<"|                                                                                        |\n";
                cout<<"|________________________________________________________________________________________|\n";
                cout<<"\n\tEnter your choice: ";
                cin>>adminChoice;
                switch( adminChoice ) 
				{
                    case 1 :
                    {
                    string username, password;
                    cout<<"__________________________________________________________________________________________\n";
                    cout<<"|                                                                                        |\n";
                    cout<<"|                   ________________________________________________                     |\n";
                    cout<<"|                  |                                                |                    |\n";
                    cout<<"|                  |             ADMIN LOG-IN INFORMATION           |                    |\n";
                    cout<<"|                  |________________________________________________|                    |\n";
                    cout<<"|                                                                                        |\n";
                    cout<<"|                                                                                        |\n";
                    cout<<"|                                                                                        |\n";
                    cout<<"|                            Enter the User-name : ";
                    cin>>username;
                    cout<<"|                                                                                        |\n";
                    cout<<"|                            Enter the Password : ";
                    cin>>password;
                    cout<<"|                                                                                        |\n";
                    cout<<"|________________________________________________________________________________________|\n";
                    system("pause");
                    break;
                    }
                            
                    case 2 :
                    break;
                            
                    default :
                    cout<<"__________________________________________________________________________________\n";
                    cout<<"|                                                                                |\n";	
                    cout<<"|                     Invalid choice. Please try again.                          |\n";
                    cout<<"|________________________________________________________________________________|\n";
                }
                } while( adminChoice != 2 );
                break;
				}

                case 2 : 
			    {
                int customerChoice;
                string email;
                do 
				{
                    system("cls"); 
                    cout<<"__________________________________________________________________________________________\n";
                    cout<<"|                                                                                        |\n";
                    cout<<"|                       _______________________________________                          |\n";
                    cout<<"|                       |                                     |                          |\n";
                    cout<<"|                       |         CUSTOMER ACCESS MODULE      |                          |\n";
                    cout<<"|                       |_____________________________________|                          |\n";
                    cout<<"|                                                                                        |\n";
                    cout<<"|                                                                                        |\n";
                    cout<<"|                                1.   Add Customer.                                      |\n";
                    cout<<"|                                2.   View Customer Accounts.                            |\n";
                    cout<<"|                                3.   Update Customer Profile.                           |\n";
                    cout<<"|                                4.   Delete Customer Profile.                           |\n";
                    cout<<"|                                5.   Exit.                                              |\n";
                    cout<<"|                                                                                        |\n";
                    cout<<"|________________________________________________________________________________________|\n";
                    cout<<"\n\tEnter your choice: ";
                    cin>>customerChoice;
                    switch( customerChoice ) 
					{
                        case 1:
                        system("cls"); 
                        cout<<"__________________________________________________________________________________________\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                   ________________________________________________                     |\n";
                        cout<<"|                  |                                                |                    |\n";
                        cout<<"|                  |                  Add Customer                  |                    |\n";
                        cout<<"|                  |________________________________________________|                    |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                            Enter the customer I'd': ";
                        cin>>customerId;
                        cout<<"|                                                                                        |\n";
                        cout<<"|                            Enter the cutomer name : ";
                        cin>>name;
                        cout<<"|                                                                                        |\n";
                        cout<<"|                            Enter the customer email : ";
                        cin>>email;
            	        customerAccess.addCustomer(customerId, name, email);                        
                        cout<<"|                                                                                        |\n";
                        cout<<"|                   ________________________________________________                     |\n";
                        cout<<"|                  |                                                |                    |\n";
                        cout<<"|                  |        New Customer Added Successfully !       |                    |\n";
                        cout<<"|                  |________________________________________________|                    |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|________________________________________________________________________________________|\n";
                        system("pause");
                        break;
               
                        case 2:
                        system("cls"); 
                        customerAccess.viewCustomerAccounts();
                        system("pause");
                        break;
                            
						case 3:
                        system("cls");
						cout<<"__________________________________________________________________________________________\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                   ________________________________________________                     |\n";
                        cout<<"|                  |                                                |                    |\n";
                        cout<<"|                  |            Update Customer Details             |                    |\n";
                        cout<<"|                  |________________________________________________|                    |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                            Enter the customer I'd': ";
                        cin>>customerId;
                        cout<<"|                                                                                        |\n";
                        cout<<"|                            Enter the new cutomer name : ";
                        cin>>name;
                        cout<<"|                                                                                        |\n";
                        cout<<"|                            Enter the new customer email : ";
                        cin>>email;
            	        customerAccess.updateCustomerProfile(customerId, name, email);                        
                        cout<<"|                                                                                        |\n";
                        cout<<"|                   ________________________________________________                     |\n";
                        cout<<"|                  |                                                |                    |\n";
                        cout<<"|                  |              Updated Successfully !            |                    |\n";
                        cout<<"|                  |________________________________________________|                    |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|________________________________________________________________________________________|\n";      
                        system("pause");
                        break;
                
                        case 4:
                        system("cls");
						cout<<"__________________________________________________________________________________\n";
                        cout<<"|                                                                                |\n";	
                        cout<<"|                     Enter the customer ID to remove : ";
                        cin>>customerId;
                        cout<<"|________________________________________________________________________________|\n"; 
                        customerAccess.deleteCustomerProfile(customerId);
                        system("pause");
                        break;
                        
						case 5:
                        break;

                        default:
                        cout<<"__________________________________________________________________________________\n";
                        cout<<"|                                                                                |\n";	
                        cout<<"|                     Invalid choice. Please try again.                          |\n";
                        cout<<"|________________________________________________________________________________|\n";
                        }
                    } while (customerChoice != 5);
                    break;
                }

                case 3: 
		        {
                int catalogChoice;
                string flavor, description, size, newDescription,  newFlavor, newSize;
                double price, newPrice ;
                do 
				{
                    system("cls"); 
                    cout<<"__________________________________________________________________________________________\n";
                    cout<<"|                                                                                        |\n";
                    cout<<"|                       _______________________________________                          |\n";
                    cout<<"|                       |                                     |                          |\n";
                    cout<<"|                       |         Cake Catalog Module         |                          |\n";
                    cout<<"|                       |_____________________________________|                          |\n";
                    cout<<"|                                                                                        |\n";
                    cout<<"|                                                                                        |\n";
                    cout<<"|                                1.   Add New Cake                                       |\n";
                    cout<<"|                                2.   Update Cake Details                                |\n";
                    cout<<"|                                3.   Remove Cake                                        |\n";
                    cout<<"|                                4.   Display All Cakes                                  |\n";
                    cout<<"|                                5.   Exit                                               |\n";
                    cout<<"|                                                                                        |\n";
                    cout<<"|________________________________________________________________________________________|\n"; 
                    cout<<"\n\tEnter your choice: ";
                    cin>>catalogChoice;
                    cin.ignore(); 
                    switch( catalogChoice ) 
					{
                        case 1:
            	        system("cls");
            	        cout<<"__________________________________________________________________________________________\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                   ________________________________________________                     |\n";
                        cout<<"|                  |                                                |                    |\n";
                        cout<<"|                  |                  Add New Cake                  |                    |\n";
                        cout<<"|                  |________________________________________________|                    |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                            Enter the cake flavor : ";
                        cin>>flavor;
                        cout<<"|                                                                                        |\n";
                        cout<<"|                            Enter the description : ";
                        cin>>description;
                        cout<<"|                                                                                        |\n";
                        cout<<"|                            Enter the price : $ ";
                        cin>>price;
						cin.ignore();
                        cout<<"|                                                                                        |\n";
                        cout<<"|                            Enter the size : ";
                        cin>>size;
            	        catalog.addCake(flavor, description, price, size);                        
                        cout<<"|                                                                                        |\n";
                        cout<<"|                   ________________________________________________                     |\n";
                        cout<<"|                  |                                                |                    |\n";
                        cout<<"|                  |           New Cake Added Successfully !        |                    |\n";
                        cout<<"|                  |________________________________________________|                    |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|________________________________________________________________________________________|\n";
            	        system("pause");
            	        break;
                    
					    case 2:
            	        system("cls");
            	        cout<<"__________________________________________________________________________________________\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                   ________________________________________________                     |\n";
                        cout<<"|                  |                                                |                    |\n";
                        cout<<"|                  |             Update Cake Details                |                    |\n";
                        cout<<"|                  |________________________________________________|                    |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                            Enter the flavor of the cake to update : ";
                        cin>>flavor;
                        cout<<"|                                                                                        |\n";
                        cout<<"|                            Enter the new flavor for the cake : ";
                        cin>>newFlavor;
                        cout<<"|                                                                                        |\n";
                        cout<<"|                            Enter the new description for the cake : ";
                        cin>>newDescription;
                        cout<<"|                                                                                        |\n";
                        cout<<"|                            Enter the new price for the cake : $ ";
                        cin>>newPrice;
						cin.ignore();
                        cout<<"|                                                                                        |\n";
                        cout<<"|                            Enter the new size for the cake : ";
                        cin>>newSize;
            	        catalog.updateCake(flavor, newFlavor, newDescription, newPrice, newSize);                        
                        cout<<"|                                                                                        |\n";
                        cout<<"|                   ________________________________________________                     |\n";
                        cout<<"|                  |                                                |                    |\n";
                        cout<<"|                  |              Updated Successfully !            |                    |\n";
                        cout<<"|                  |________________________________________________|                    |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|________________________________________________________________________________________|\n";
            	        system("pause");
            	        break;
                    
					    case 3:
            	        system("cls");
            	        cout<<"__________________________________________________________________________________\n";
                        cout<<"|                                                                                |\n";	
                        cout<<"|                     Enter the flavor to remove : ";
                        getline(cin, flavor);
                        cout<<"|________________________________________________________________________________|\n";
            	        catalog.removeCake(flavor);
            	        system("pause");
            	        break;
            
                        case 4:
            	        system("cls");
            	        catalog.displayCakes();
            	        system("pause");
            	        break;
                    
					    case 5:
            	        break;
            
                        default:
            	        cout<<"__________________________________________________________________________________\n";
                        cout<<"|                                                                                |\n";	
                        cout<<"|                     Invalid choice. Please try again.                          |\n";
                        cout<<"|________________________________________________________________________________|\n";
                        }
                    } while( catalogChoice != 5 );
                    break;
                }

                case 4 : 
			    {
                int orderChoice, orderId;
                do 
				{
                    system("cls"); 
                    cout<<"__________________________________________________________________________________________\n";
                    cout<<"|                                                                                        |\n";
                    cout<<"|                       _______________________________________                          |\n";
                    cout<<"|                       |                                     |                          |\n";
                    cout<<"|                       |       Order Management Module       |                          |\n";
                    cout<<"|                       |_____________________________________|                          |\n";
                    cout<<"|                                                                                        |\n";
                    cout<<"|                                                                                        |\n";
                    cout<<"|                                1.   Add Order                                          |\n";
                    cout<<"|                                2.   Track Orders                                       |\n";
                    cout<<"|                                3.   Update Order Status                                |\n";
                    cout<<"|                                4.   Cancel Order                                       |\n";
                    cout<<"|                                5.   Exit.                                              |\n";
                    cout<<"|                                                                                        |\n";
                    cout<<"|________________________________________________________________________________________|\n"; 
                    cout<<"\n\tEnter your choice: ";
                    cin>>orderChoice;
                    switch( orderChoice ) 
					{
                        case 1 :
                        system("cls");
                        cout<<"__________________________________________________________________________________________\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                   ________________________________________________                     |\n";
                        cout<<"|                  |                                                |                    |\n";
                        cout<<"|                  |                    Add Order                   |                    |\n";
                        cout<<"|                  |________________________________________________|                    |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                            Enter the Order ID: ";
                        cin>>orderId;
                        cout<<"|                                                                                        |\n";
                        cout<<"|                            Enter the Customer ID : ";
                        cin>>customerId;
                        cout<<"|                                                                                        |\n";
                        cout<<"|                            Enter the Order status( Pending,Shipped,Delivered,Cancelled ) : ";
                        cin>>status;
            	        orderManagement.addOrder(orderId, customerId, status);                        
                        cout<<"|                                                                                        |\n";
                        cout<<"|                   ________________________________________________                     |\n";
                        cout<<"|                  |                                                |                    |\n";
                        cout<<"|                  |          New Order Added Successfully !        |                    |\n";
                        cout<<"|                  |________________________________________________|                    |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|________________________________________________________________________________________|\n";
                        system("pause");    
                        break;

                        case 2:
                        system("cls");
                        orderManagement.trackOrders();
                        system("pause");
                        break;

                        case 3:
                        system("cls");
                        cout<<"__________________________________________________________________________________________\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                   ________________________________________________                     |\n";
                        cout<<"|                  |                                                |                    |\n";
                        cout<<"|                  |                 Update Order                   |                    |\n";
                        cout<<"|                  |________________________________________________|                    |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                            Enter the Order ID: ";
                        cin>>orderId;
                        cout<<"|                                                                                        |\n";
                        cout<<"|                            Enter new Order status( Pending,Shipped,Delivered,Cancelled ) : ";
                        cin>>status;
                        orderManagement.updateOrderStatus(orderId, status);
                        cout<<"|                                                                                        |\n";
                        cout<<"|                   ________________________________________________                     |\n";
                        cout<<"|                  |                                                |                    |\n";
                        cout<<"|                  |              Updated Successfully !            |                    |\n";
                        cout<<"|                  |________________________________________________|                    |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|________________________________________________________________________________________|\n";
                        system("pause");
                        break;

                        case 4:
                        system("cls");
                        cout<<"__________________________________________________________________________________\n";
                        cout<<"|                                                                                |\n";	
                        cout<<"|                     Enter the Order ID to cancel : ";
                        cin>>orderId;
                        cout<<"|________________________________________________________________________________|\n";
                        orderManagement.cancelOrder(orderId);
                        system("pause");
                        break;

                        case 5:
                        break;

                        default:
                        system("cls");
                        cout<<"__________________________________________________________________________________\n";
                        cout<<"|                                                                                |\n";	
                        cout<<"|                     Invalid choice. Please try again.                          |\n";
                        cout<<"|________________________________________________________________________________|\n";
                        }
                    } while (orderChoice != 5);
                    break;
                }
            
                case 5 :
                {
                int choice, id;
                double discount;
                cakeNode* menu = nullptr;
                // Predefined menu
                addCake(menu, 1, "Chocolate Cake", 500.0);
                addCake(menu, 2, "Vanilla Cake", 400.0);
                addCake(menu, 3, "Red Velvet Cake", 600.0);
                do 
			    {
                    system("cls");
                    cout<<"__________________________________________________________________________________________\n";
                    cout<<"|                                                                                        |\n";
                    cout<<"|                       _______________________________________                          |\n";
                    cout<<"|                       |                                     |                          |\n";
                    cout<<"|                       |          Cake Discount Module       |                          |\n";
                    cout<<"|                       |_____________________________________|                          |\n";
                    cout<<"|                                                                                        |\n";
                    cout<<"|                                                                                        |\n";
                    cout<<"|                                1.   Display Menu                                       |\n";
                    cout<<"|                                2.   Apply Discount to a Cake.                          |\n";
                    cout<<"|                                3.   Checkout                                           |\n";
                    cout<<"|                                4.   Exit.                                              |\n";
                    cout<<"|                                                                                        |\n";
                    cout<<"|________________________________________________________________________________________|\n"; 
                    cout<<"\n\tEnter your choice: ";
                    cin>>choice;
                    switch( choice ) 
					{
                        case 1: 
            	        system("cls");
                        displayMenu(menu);
                        system("pause");
                        break;
            
			            case 2 : 
						{
            	        system("cls");
                        cout<<"__________________________________________________________________________________________\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                   ________________________________________________                     |\n";
                        cout<<"|                  |                                                |                    |\n";
                        cout<<"|                  |            Apply Discount to a Cake            |                    |\n";
                        cout<<"|                  |________________________________________________|                    |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                            Enter the Cake ID to apply discount : ";
                        cin>>id;
                        cout<<"|                                                                                        |\n";
                        cout<<"|                            Enter Discount Percentage (0-100) : ";
                        cin>>discount;
                        if( discount<0 || discount>100 ) 
						{
					    cout<<"__________________________________________________________________________________________\n";
				    	cout<<"|                                                                                        |\n";
                        cout<<"|          Invalid discount percentage! Please enter a value between 0 and 100.          |\n";
                        cout<<"|________________________________________________________________________________________|\n";
                        } 
						else 
						{
                        applyDiscount(menu, id, discount);
                        }
                        cout<<"|                                                                                        |\n";
                        cout<<"|________________________________________________________________________________________|\n";    
                        system("pause");
                        break;
                        }
                        
                        case 3:
            	        system("cls");
                        checkout(menu);
                        system("pause");
                        break;
            
			            case 4:
                        break;
               
                        default:
                        cout<<"__________________________________________________________________________________\n";
                        cout<<"|                                                                                |\n";	
                        cout<<"|                     Invalid choice. Please try again.                          |\n";
                        cout<<"|________________________________________________________________________________|\n";
                        }
                    } while (choice != 4);
                    break;
                }

                case 6 : 
		        {
                int deliveryChoice, personnelId;
                do 
			    {
                    system("cls");  
                    cout<<"__________________________________________________________________________________________\n";
                    cout<<"|                                                                                        |\n";
                    cout<<"|                       _______________________________________                          |\n";
                    cout<<"|                       |                                     |                          |\n";
                    cout<<"|                       |        Delivery Control MODULE      |                          |\n";
                    cout<<"|                       |_____________________________________|                          |\n";
                    cout<<"|                                                                                        |\n";
                    cout<<"|                                                                                        |\n";
                    cout<<"|                                1.   Add Personnel                                      |\n";
                    cout<<"|                                2.   Update Personnel Status                            |\n";
                    cout<<"|                                3.   View Personnel                                     |\n";
                    cout<<"|                                4.   Exit.                                              |\n";
                    cout<<"|                                                                                        |\n";
                    cout<<"|________________________________________________________________________________________|\n"; 
                    cout<<"\n\tEnter your choice: ";
                    cin>>deliveryChoice;
                    switch(deliveryChoice)
				    {
				    	case 1:
                        system("cls");
                        cout<<"__________________________________________________________________________________________\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                   ________________________________________________                     |\n";
                        cout<<"|                  |                                                |                    |\n";
                        cout<<"|                  |                  Add Personnel                 |                    |\n";
                        cout<<"|                  |________________________________________________|                    |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                            Enter the Personnel I'd': ";
                        cin>>personnelId;
                        cout<<"|                                                                                        |\n";
                        cout<<"|                            Enter the Personnel name : ";
                        cin>>name;
                        cout<<"|                                                                                        |\n";
                        cout<<"|                            Enter the Status (Available/Busy) : ";
                        cin>>status;
            	        control.addPersonnel(personnelId, name, status);                        
                        cout<<"|                                                                                        |\n";
                        cout<<"|                   ________________________________________________                     |\n";
                        cout<<"|                  |                                                |                    |\n";
                        cout<<"|                  |        New Personnel Added Successfully !       |                    |\n";
                        cout<<"|                  |________________________________________________|                    |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|________________________________________________________________________________________|\n";
                        system("pause");
                        break;
                        
                        case 2:
                        system("cls");
                        cout<<"__________________________________________________________________________________________\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                   ________________________________________________                     |\n";
                        cout<<"|                  |                                                |                    |\n";
                        cout<<"|                  |                Update Personnel                |                    |\n";
                        cout<<"|                  |________________________________________________|                    |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                            Enter the Personnel ID : ";
                        cin>>personnelId;
						cout<<"|                                                                                        |\n";
                        cout<<"|                            Enter the Status (Available/Busy) : ";
                        cin>>status;    
                        control.updateStatus(personnelId, status);
                        cout<<"|                                                                                        |\n";
                        cout<<"|                   ________________________________________________                     |\n";
                        cout<<"|                  |                                                |                    |\n";
                        cout<<"|                  |              Updated Successfully !            |                    |\n";
                        cout<<"|                  |________________________________________________|                    |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|________________________________________________________________________________________|\n";
                        system("pause");
                        break;

                        case 3:
                        system("cls");
                        control.viewPersonnel();
                        system("pause");
                        break;

                        case 4:
                        goto AM_TITLE;
                        break;

                        default:
                        system("cls");
                        cout<<"__________________________________________________________________________________\n";
                        cout<<"|                                                                                |\n";	
                        cout<<"|                     Invalid choice. Please try again.                          |\n";
                        cout<<"|________________________________________________________________________________|\n";
                        }
                    } while (deliveryChoice != 4);
                    break;
				}
            
                case 7 :
                {
                	F.addOrder("Chocolate", "Medium", 3, 1100);
                    F.addOrder("Vanilla", "Large", 2, 2000);  
                    double singleCakePrice;
                    cout<<"__________________________________________________________________________________________\n";
	                cout<<"|                                                                                        |\n";
                    cout<<"|                        Enter the price of a single cake : ";
                    cin>>singleCakePrice;
                    cout<<"|                                                                                        |\n"; 
                    cout<<"|________________________________________________________________________________________|\n";
                    F.generateSalesReport(singleCakePrice);
					system("pause");	
			    }

                case 8 :
            	    cout<<"__________________________________________________________________________________\n";
                    cout<<"|                                                                                |\n";	
                    cout<<"|                     Exiting the program. Thank you!                          |\n";
                    cout<<"|________________________________________________________________________________|\n";
                    goto CMS_Title;
                break;

                default:
                    cout<<"__________________________________________________________________________________\n";
                    cout<<"|                                                                                |\n";	
                    cout<<"|                     Invalid choice. Please try again.                          |\n";
                    cout<<"|________________________________________________________________________________|\n";
                }
                system("pause");
            } 
	        while (userType != 6);
            	
            // Customer Functionallities
            case 2:
            while( true ) 
			{
			CM_Title:
            system("cls");
            displayCustomerOptions();
            int customerChoice;
            cin>>customerChoice;
            switch( customerChoice ) 
			{
                case 1 :
				{	
                    system("cls");
                    string name, email, mobile, username, password;
                    cin.ignore();
                    // Customer Sign-Up
                    cout<<"__________________________________________________________________________________________\n";
                    cout<<"|                                                                                        |\n";
                    cout<<"|                   ________________________________________________                     |\n";
                    cout<<"|                  |                                                |                    |\n";
                    cout<<"|                  |          CUSTOMER SIGN-UP INFORMATION          |                    |\n";
                    cout<<"|                  |________________________________________________|                    |\n";
                    cout<<"|                                                                                        |\n";
                    cout<<"|                                                                                        |\n";
                    cout<<"|                            Enter Your Name : "; 
                    getline(cin, name);
                    cout<<"|                                                                                        |\n";
                    cout<<"|                            Enter Your Email : ";
                    getline(cin, email);
                    cout<<"|                                                                                        |\n";
                    cout<<"|                            Enter Your Mobile no. : ";
                    getline(cin, mobile);
                    cout<<"|                                                                                        |\n";
                    cout<<"|                            Enter Your User-name : ";
                    getline(cin, username);
                    cout<<"|                                                                                        |\n";
                    cout<<"|                            Enter Your Password : ";
                    getline(cin, password);
                    cout<<"|                                                                                        |\n";
                    cout<<"|________________________________________________________________________________________|\n";
                    CP.signUp(name, email, mobile, username, password);
                    system("pause");
                    goto CM_Title;
                    break;
                }

                case 2 :
                {	
                    system("cls");
                    string username, password;
                    cin.ignore(); 
                    // Customer Log-In
                    cout<<"__________________________________________________________________________________________\n";
                    cout<<"|                                                                                        |\n";
                    cout<<"|                   ________________________________________________                     |\n";
                    cout<<"|                  |                                                |                    |\n";
                    cout<<"|                  |           CUSTOMER LOG-IN INFORMATION          |                    |\n";
                    cout<<"|                  |________________________________________________|                    |\n";
                    cout<<"|                                                                                        |\n";
                    cout<<"|                                                                                        |\n";
                    cout<<"|                                                                                        |\n";
                    cout<<"|                            Enter the User-name : ";
                    getline(cin, username);
                    cout<<"|                                                                                        |\n";
                    cout<<"|                            Enter the Password : ";
                    getline(cin, password);
                    cout<<"|                                                                                        |\n";
                    cout<<"|________________________________________________________________________________________|\n";
                    system("pause");    
					if( CP.login( username, password ) ) 
					{
                        while( true ) 
						{
							system("cls");
                            displayCustomerModules();
                            int moduleChoice; 
                            cin>>moduleChoice;
                            switch( moduleChoice ) 
							{		
								case 1 :                   
									// Browse Cake
									system("cls");
                                    displayBrowseCake();
                                    system("pause");
                                    break;
                                
                                case 2 :	
                                    // Browse Cake
                                    system("cls");
                                    displayBrowseCake();
                                    OM.placeOrder();
                                    system("pause");
                                    break;
                                    
                                case 3 :	
                                    // Track Order
                                    system("cls");
                                    OM.displayTrackOrder();
                                    system("pause");
                                    break;                                

                                case 4 :
                                	system("cls");
                                    DT.displayTrackDelivery();
									system("pause"); 
                                    break;
                                	
								case 5 :
								{	
									system("cls");
                                    DisplayPaymentOptions();
                                    string name, phone;
                                    int paymentChoice;
                                    cin>>paymentChoice;
                                    if( paymentChoice==1 ) 
									{
                                        cout<<"|                                                                                  |\n";
                                        cout<<"|                                                                                  |\n";
                                        cout<<"|                            Enter your name : ";
                                        cin.ignore(); 
                                        getline( cin,name );
                                        cout<<"|                            Enter your phone number : ";
                                        getline( cin,phone );
                                        PL.paymentOption( name, phone );
                                        cout<<"|                                                                                  |\n";
                                        cout<<"|                     Thank you !! Your order is being processed.                  |\n";
                                        cout<<"|                                                                                  |\n";
                                        cout<<"|__________________________________________________________________________________|\n";
                                        system("pause");
                                    }
                                    else if( paymentChoice==2) 
									{
										cout<<"____________________________________________________________________________________\n";
										cout<<"|                                                                                  |\n";
                                        cout<<"|                                                                                  |\n";
                                        cout<<"|                           Your Delivery is on the way !!                         |\n";
                                        cout<<"|                                                                                  |\n";
                                        cout<<"|                  Just give the total payment to the delivery man !!              |\n";
                                        cout<<"|                                                                                  |\n";
                                        cout<<"|__________________________________________________________________________________|\n";
                                        system("pause");
                                    }
                                    else 
									{
										cout<<"____________________________________________________________________________________\n";
                                        cout<<"|                                                                                  |\n";
                                        cout<<"|                       Invalid choice !! please 1 or 2                            |\n";
                                        cout<<"|                                                                                  |\n";
                                        cout<<"|__________________________________________________________________________________|\n";
                                        system("pause");
                                        return 0;  
                                    }
                                }
                                    break;
                                
                                case 6 :
                                {	
                                	system("cls");
                                	int rating;
                                	string feedback, name;
                                    cout<<"____________________________________________________________________________________\n";
                                    cout<<"|                                                                                  |\n";
                                    cout<<"|                       _______________________________________                    |\n";
                                    cout<<"|                       |                                     |                    |\n";
                                    cout<<"|                       |          FEEDBACK & RATINGS         |                    |\n";
                                    cout<<"|                       |_____________________________________|                    |\n";
                                    cout<<"|                                                                                  |\n";
                                    cout<<"|                                                                                  |\n";
                                    cout<<"|                            Name : ";
                                    cin.ignore();  
                                    getline(cin, name );
                                    cout<<"|                            Feed-back : ";
                                    cin.ignore();  
                                    getline(cin, feedback );
                                    cout<<"|                            Ratings from ( 1-5 ) : ";
                                    cin>>rating;
                                    if( rating<1 || rating>5 ) 
									{
										cout<<"|                                                                                  |\n";
                                        cout<<"|                 Invalid rating! Please enter a rating between 1 and 5.           |\n";
                                        cout<<"|                                                                                  |\n";
                                        return 0;  
                                    }
                                    FL.addFeedback( name, feedback, rating);
                                    cout<<"|                                                                                  |\n";
                                    cout<<"|                     _________________________________________________            |\n";
                                    cout<<"|                     |                                               |            |\n";
                                    cout<<"|                     |     THANK YOU FOR THIS BEAUTIFUL REVIEW       |            |\n";
                                    cout<<"|                     |_______________________________________________|            |\n";
                                    cout<<"|                                                                                  |\n";
                                    cout<<"|__________________________________________________________________________________|\n";
                                    system("pause");
                                }
                                break;
                                
                                case 7 :
                                	system("cls");
                                    cout<<"__________________________________________________________________________________________\n";
                                    cout<<"|                                                                                        |\n";
                                    cout<<"|                   ________________________________________________                     |\n";
                                    cout<<"|                  |                                                |                    |\n";
                                    cout<<"|                  |           EXITING  CUSTOMER  MODULES           |                    |\n";
                                    cout<<"|                  |________________________________________________|                    |\n";
                                    cout<<"|                                                                                        |\n";
                                    cout<<"|________________________________________________________________________________________|\n";
                                    system("pause");
                                    goto CM_Title;
                                    break;
                                
                                default :
                                	system("cls");
                                	cout<<"__________________________________________________________________________________\n";
                                    cout<<"|                                                                                |\n";
                                    cout<<"|                          Feature under development!                            |\n";
                                    cout<<"|________________________________________________________________________________|\n";
                                    system("pause");
                                    
                                }
                            }
                        }
                        break;
                    }
                    break;

                    case 3:
                    	system("cls");
                        // Exit to the welcome page
                        cout<<"__________________________________________________________________________________________\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|                   ________________________________________________                     |\n";
                        cout<<"|                  |                                                |                    |\n";
                        cout<<"|                  |           EXITING  CUSTOMER  OPTIONS           |                    |\n";
                        cout<<"|                  |________________________________________________|                    |\n";
                        cout<<"|                                                                                        |\n";
                        cout<<"|________________________________________________________________________________________|\n";
                        system("pause");
                        break;

                    default:
                    	system("cls");
                    	cout<<"__________________________________________________________________________________\n";
                        cout<<"|                                                                                |\n";
                        cout<<"|             Invalid choice. Returning to Customer Options...                   |\n";
                        cout<<"|________________________________________________________________________________|\n";
                        system("pause");
                        break;
                }
                break;

            default:
            	system("cls");
            	cout<<"__________________________________________________________________________________\n";
                cout<<"|                                                                                |\n";	
                cout<<"|                     Invalid choice. Please try again.                          |\n";
                cout<<"|________________________________________________________________________________|\n";
                system("pause");
                break;
            }
          }
        }

    return 0;
}