#include <bits/stdc++.h>
using namespace std;
#include <limits.h>
#include <unistd.h>

// Function to check the date
bool check_date(string date)
{
    if (date.length() != 10)
    {
        throw invalid_argument("Date isn't valid: The date must be in the format GG/MM/AAAA.");
    }
    if (date[2] != '/' || date[5] != '/')
    {
        throw invalid_argument("Date isn't valid: The date must be in the format GG/MM/AAAA.");
    }
    return true;
}

// Class for Customer
class Customer
{
    // Private attributes
    string name, lastname, date, email, phone;

public:
    // Constructor with parameters
    Customer(string _name, string _lastname, string _date, string _email, string _phone)
    {
        name = _name;
        lastname = _lastname;
        if (check_date(_date))
        {
            date = _date;
        }
        else
        {
            cout << "Please enter a valid date." << endl;
        }
        email = _email;
        phone = _phone;
    }
    // prints the information of the customer
    void info_customer()
    {
        cout << "\nThe information of the customer is: " << endl;
        cout << "Name: " << name << endl;
        cout << "Lastname: " << lastname << endl;
        cout << "Date of Birth: " << date << endl;
        cout << "Email: " << email << endl;
        cout << "Phone: " << phone << endl
             << endl;
    }
    // Check if the customer is equal to the customer provided in input
    bool operator==(const Customer &customer) const
    {
        return (name == customer.name &&
                lastname == customer.lastname &&
                date == customer.date &&
                email == customer.email &&
                phone == customer.phone);
    }
    // Getters
    string get_name()
    {
        return name;
    }

    string get_lastname()
    {
        return lastname;
    }
    string get_date()
    {
        return date;
    }
    string get_email()
    {
        return email;
    }
    string get_phone()
    {
        return phone;
    }

    // Setters
    void set_name(string _name)
    {
        name = _name;
    }

    void set_lastname(string _lastname)
    {
        lastname = _lastname;
    }

    void set_date(string _date)
    {
        if (check_date(_date))
        {
            date = _date;
        }
        else
        {
            cout << "Please enter a valid date." << endl;
        }
    }
    void set_email(string _email)
    {
        email = _email;
    }
    void set_phone(string _phone)
    {
        phone = _phone;
    }
};

// Class for Interaction
class Interaction
{
    // Private attributes
    string type_of_appointment, date;
    bool outcome;
    Customer *ptr_customer;

public:
    // Constructor with parameters
    Interaction(string _type_of_appointment, string _date, bool _outcome, Customer *_ptr_customer)
    {
        type_of_appointment = _type_of_appointment;
        date = _date;
        outcome = _outcome;
        ptr_customer = _ptr_customer;
    }
    // Prints the interaction of the customer
    void info_interaction()
    {
        cout << "\nThe information of the interaction for customer " << ptr_customer->get_name() << " " << ptr_customer->get_lastname() << " is: " << endl;
        cout << "Type of Appointment: " << type_of_appointment << endl;
        cout << "Date: " << date << endl;
        cout << "Outcome: " << outcome << endl
             << endl;
    }
    // Check if the customer that have a interaction is equal to the customer provided in input
    bool find_interaction(Customer customer)
    {
        int res_name = ptr_customer->get_name().compare(customer.get_name());
        int res_lastname = ptr_customer->get_lastname().compare(customer.get_lastname());

        if (res_name == 0 && res_lastname == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // Getters
    string get_type_of_appointment()
    {
        return type_of_appointment;
    }
    string get_date()
    {
        return date;
    }
    bool get_outcome()
    {
        return outcome;
    }
    Customer *get_customer()
    {
        return ptr_customer;
    }
};

// Class for Customer Management
class Customer_Management
{
public:
    /*
    I decide to use list instead of vector
    - With vector is possible to use the operator [] to access the elements of the vector
      (but it reallocates the memory when the size of the vector is changed and so invalidates the pointers to the elements of the vector)
    - With list use the iterator to access the elements of the list but it does not invalidate the pointers to the elements of the list
    */

    // List of customers and interactions
    list<Customer> customer_management;
    list<Interaction> customer_interactions;

    // Adds a customer to the vector
    // const --> to avoid changes in the object and & --> to avoid copying the object and pass it by reference
    void add_customer(const Customer &customer)
    {
        // Add the new customer to the queue. push_back() method is incluse in std::list
        customer_management.push_back(customer);
    }
    // Adds an interaction to the vector
    void add_interaction(const Interaction &interaction)
    {
        customer_interactions.push_back(interaction);
    }
    // Removes a customer from the list
    void remove_customer(Customer *customer)
    {
        // Remove the customer from the list. remove() method is incluse in std::list
        customer_management.remove(*customer);
    }
    // Prints the information of the customer
    void info_customers(Customer customer)
    {
        customer.info_customer();
    }
    // Prints the information of all the customers
    void info_all_customers()
    {
        for (auto iterator = customer_management.begin(); iterator != customer_management.end(); ++iterator)
        {
            iterator->info_customer();
        }
    }
    // Prints the information of all the interactions for a customer
    void info_all_interactions(Customer customer)
    {
        // keyword "auto" --> to avoid the type of the iterator
        int flag = 0;
        for (auto iterator = customer_interactions.begin(); iterator != customer_interactions.end(); ++iterator)
        {
            if (iterator->find_interaction(customer))
            {
                flag++;
                iterator->info_interaction();
            }
            if (flag == 0)
            {
                cout << "The customer does not have any interaction." << endl;
            }
        }
    }
    // Check if a customer exists in the vector
    bool exist_customer(string _name, string _lastname)
    {
        for (auto iterator = customer_management.begin(); iterator != customer_management.end(); ++iterator)
        {
            if (iterator->get_name() == _name && iterator->get_lastname() == _lastname)
            {
                return true;
            }
        }
        return false;
    }

    // Recover a customer from the vector
    Customer *recover_customer(string _name, string _lastname)
    {
        for (auto iterator = customer_management.begin(); iterator != customer_management.end(); ++iterator)
        {
            if (iterator->get_name() == _name && iterator->get_lastname() == _lastname)
            {
                Customer *ptr_customer = &(*iterator);
                return ptr_customer;
            }
        }
        return NULL;
    }
};

// Function to select an option
int option_function()
{
    void clean_buffer();
    cout << "Please select an option: " << endl;
    cout << "1. Add a new customer" << endl;
    cout << "2. Add a new interaction for a specific customer" << endl;
    cout << "3. View all customers" << endl;
    cout << "4. View all interactions of a customer" << endl;
    cout << "5. Modify a customer" << endl;
    cout << "6. Delete a customer" << endl;
    cout << "7. Save and Exit" << endl;
    // Pulisci il buffer
    clean_buffer();
    int option;
    cin >> option;
    return option;
}

// Function to clean the buffer
void clean_buffer()
{
    while (getchar() != '\n' && getchar() != EOF)
        ;
}
// Function to insert the name of the customer
string insert_name_customer()
{
    string name;
    cout << "Please enter the name of the customer: " << endl;
    clean_buffer();
    cin >> name;
    return name;
}
// Function to insert the lastname of the customer
string insert_lastname_customer()
{
    string lastname;
    cout << "Please enter the lastname of the customer: " << endl;
    clean_buffer();
    cin >> lastname;
    return lastname;
}
// Function to insert the date of the customer
string insert_date_customer()
{
    string date;
    cout << "Please enter the date of birth of the customer: [DD/MM/YYYY] " << endl;
    clean_buffer();
    cin >> date;
    return date;
}
// Function to insert the email of the customer
string insert_email_customer()
{
    string email;
    cout << "Please enter the email of the customer: " << endl;
    clean_buffer();
    cin >> email;
    return email;
}
// Function to insert the phone of the customer
string insert_phone_customer()
{
    string phone;
    cout << "Please enter the phone of the customer: " << endl;
    clean_buffer();
    cin >> phone;
    return phone;
}
// Function to insert the type of appointment
string insert_type_of_appointment()
{
    string type_of_appointment;
    cout << "Please enter the type of appointment: " << endl;
    clean_buffer();
    cin >> type_of_appointment;
    return type_of_appointment;
}
// Function to insert the date of the appointment
string insert_date_interaction()
{
    string date;
    cout << "Please enter the date of the appointment: [DD/MM/YYYY] " << endl;
    clean_buffer();
    cin >> date;
    return date;
}
// Function to insert the outcome of the appointment
bool insert_outcome_interaction()
{
    string outcome;
    cout << "Please enter the outcome of the appointment: [good/not good]" << endl;
    clean_buffer();
    cin >> outcome;
    return outcome == "good" ? true : false;
}

int main()
{
    cout << "Welcome to InsuraPro Solutions. We are dedicated to providing the highest quality customer management for insurance companies." << endl;
    Customer_Management cm;
    // percorso corrente
    char cwd[PATH_MAX];
    // percorso completo dove salvare il file
    char full_path[PATH_MAX];

    if (strcmp(cwd, "C:\\Users\\Utente\\Profession AI\\Project_C++") != 0)
    {
        chdir("C:\\Users\\Utente\\Profession AI\\Project_C++");
    }
    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {
        perror("Errore");
        return 0;
    }
    else
    {
        printf("La directory corrente è: %s\n", cwd);
    }
    // Unisci percorso corrente e percorso relativo
    snprintf(full_path, sizeof(full_path), "%s\\%s", cwd, "file.txt");
    clean_buffer();
    cout << "Have you already a CRM? [y/n]" << endl;
    string response;
    cin >> response;
    if (response == "y")
    {
        // Upload the file
        cout << "Great! Let's start by upload the file" << endl;
        FILE *file;
        file = fopen(full_path, "r");
        if (file == NULL)
        {
            cout << "Error in opening the file." << endl;
            exit(1);
        }
        char line[200];
        string name, lastname, date, email, phone, type_of_appointment, date_appointment, outcome;
        int number_interactions;
        while (fgets(line, sizeof(line), file) != NULL)
        {
            // Ignore the spaces at the beginning of the line
            int i = 0;
            while (line[i] == ' ')
                i++;
            if (!isdigit(line[i]))
            {
                // Read the information of the customer
                sscanf(line, "%s %s %s %s %s", name.c_str(), lastname.c_str(), date.c_str(), email.c_str(), phone.c_str());
                Customer custom1(name, lastname, date, email, phone);
                cm.add_customer(custom1);
            }
            else
            {
                // Read the information of the interaction
                sscanf(line, "%d %s %s %s %s %s", &number_interactions, name.c_str(), lastname.c_str(), type_of_appointment.c_str(), date_appointment.c_str(), outcome.c_str());
                Customer *ptr_customer = cm.recover_customer(name, lastname);
                Interaction inter1(type_of_appointment, date_appointment, outcome == "good" ? true : false, ptr_customer);
                cm.add_interaction(inter1);
            }
        }
    }
    cout << "Great! Let's start!" << endl;
    int option;
    do
    {
        option = option_function();
        switch (option)
        {
        case 1:
        {
            cout << "Please enter the information of the customer: " << endl;
            string name = insert_name_customer();
            string lastname = insert_lastname_customer();
            string date = insert_date_customer();
            string email = insert_email_customer();
            string phone = insert_phone_customer();
            Customer custom1(name, lastname, date, email, phone);
            cm.add_customer(custom1);
            break;
        }
        case 2:
        {
            string name = insert_name_customer();
            string lastname = insert_lastname_customer();
            if (cm.exist_customer(name, lastname))
            {
                cout << "Please enter the information of the interaction: " << endl;
                string type_of_appointment = insert_type_of_appointment();
                string date = insert_date_interaction();
                bool outcome = insert_outcome_interaction();
                Customer *ptr_customer = cm.recover_customer(name, lastname);
                Interaction inter1(type_of_appointment, date, outcome, ptr_customer);
                cm.add_interaction(inter1);
            }
            else
            {
                cout << "The customer does not exist." << endl;
            };

            break;
        }
        case 3:
        {
            cm.info_all_customers();
            break;
        }
        case 4:
        {
            string name = insert_name_customer();
            string lastname = insert_lastname_customer();
            if (cm.exist_customer(name, lastname))
            {
                Customer *ptr_customer = cm.recover_customer(name, lastname);
                cm.info_all_interactions(*ptr_customer);
            }
            else
            {
                cout << "The customer does not exist." << endl;
            };

            break;
        }
        case 5:
        {
            string name = insert_name_customer();
            string lastname = insert_lastname_customer();
            if (cm.exist_customer(name, lastname))
            {
                Customer *ptr_customer = cm.recover_customer(name, lastname);
                cout << "What do you change? [name, lastname, date, email, phone] " << endl;
                string response;
                cin >> response;
                if (response == "name")
                {
                    string new_name = insert_name_customer();
                    ptr_customer->set_name(new_name);
                }
                else if (response == "lastname")
                {
                    string new_lastname = insert_lastname_customer();
                    ptr_customer->set_lastname(new_lastname);
                }
                else if (response == "date")
                {
                    string new_date = insert_date_customer();
                    ptr_customer->set_date(new_date);
                }
                else if (response == "email")
                {
                    string new_email = insert_email_customer();
                    ptr_customer->set_email(new_email);
                }
                else if (response == "phone")
                {
                    string new_phone = insert_phone_customer();
                    ptr_customer->set_phone(new_phone);
                }
                else
                {
                    cout << "Please enter a valid option." << endl;
                }
            }
            else
            {
                cout << "The customer does not exist." << endl;
            }
            break;
        }
        case 6:
        {
            string name = insert_name_customer();
            string lastname = insert_lastname_customer();
            if (cm.exist_customer(name, lastname))
            {
                Customer *ptr_customer = cm.recover_customer(name, lastname);
                cm.remove_customer(ptr_customer);
            }
            else
            {
                cout << "The customer does not exist." << endl;
            }
            break;
        }
        case 7:
        {
            cout << "Saving the file..." << endl;
            clean_buffer();
            // Save the file
            FILE *file;
            file = fopen(full_path, "w");
            if (file == NULL)
            {
                cout << "Error in creating the file." << endl;
                exit(1);
            }
            for (auto iterator = cm.customer_management.begin(); iterator != cm.customer_management.end(); ++iterator)
            {
                fprintf(file, "%s %s %s %s %s\n", iterator->get_name().c_str(), iterator->get_lastname().c_str(), iterator->get_date().c_str(), iterator->get_email().c_str(), iterator->get_phone().c_str());
                for (auto iterator2 = cm.customer_interactions.begin(); iterator2 != cm.customer_interactions.end(); ++iterator2)
                {
                    if (iterator2->get_customer()->get_name() == iterator->get_name() && iterator2->get_customer()->get_lastname() == iterator->get_lastname())
                    {
                        bool outcome = iterator2->get_outcome();
                        string outcome_str = outcome ? "good" : "not_good";
                        int number_interactions = 1;
                        fprintf(file, "%d %s %s %s %s %s\n", number_interactions, iterator2->get_customer()->get_name().c_str(), iterator2->get_customer()->get_lastname().c_str(), iterator2->get_type_of_appointment().c_str(), iterator2->get_date().c_str(), outcome_str.c_str());
                        number_interactions++;
                    }
                }
            }
            cout << "Thank you for using InsuraPro Solutions. Have a great day!" << endl;
            fclose(file);
            break;
        }
        default:
        {
            cout << "Please enter a valid option." << endl;
            break;
        }
        }
    } while (option != 7);
}