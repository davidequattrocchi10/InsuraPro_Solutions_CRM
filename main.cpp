#include <bits/stdc++.h>
using namespace std;
#include <limits.h>

// Function to fix the format of the name and lastname
string fix_format(string name)
{
    if (name.empty())
    {
        throw invalid_argument("Name isn't valid: The name mustn't be empty.");
    }
    // Remove the spaces at the beginning of the string
    name.erase(0, name.find_first_not_of(" \t\n"));
    // Remove the spaces at the end of the string
    name.erase(name.find_last_not_of(" \t\n") + 1);
    // Convert the first letter to uppercase
    name[0] = toupper(name[0]);
    // Convert the other letters to lowercase
    for (int i = 1; i < name.length(); i++)
    {
        name[i] = tolower(name[i]);
    }
    return name;
}
// Function to check name and lastname
bool check_name_lastname(string name)
{
    for (int i = 0; i < name.length(); i++)
    {
        if (!isalpha(name[i]))
        {
            throw invalid_argument("Name isn't valid: The name must include only letters.");
        }
    }
    return true;
}
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

// Function to check if the phone number contains only numbers
bool only_ten_numbers(string phone_number)
{
    if (phone_number.length() != 10)
    {
        throw invalid_argument("Phone number isn't valid: The phone number must be ten numbers long.");
    }
    for (int i = 0; i < phone_number.length(); i++)
    {
        if (!isdigit(phone_number[i]))
        {
            throw invalid_argument("Phone number isn't valid: The phone number must include only numbers.");
        }
    }
    return true;
}
// Function to verify the presence of @ and . in the email
bool verify_email(string email)
{
    int at = 0;
    int dot = 0;
    for (int i = 0; i < email.length(); i++)
    {
        if (email[i] == '@')
        {
            at++;
        }
        if (email[i] == '.')
        {
            dot++;
        }
    }
    if (at == 1 && dot >= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
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
        if (!check_name_lastname(_name))
        {
            throw invalid_argument("Name isn't valid: The name must include only letters.");
        }
        name = _name;

        if (!check_name_lastname(_lastname))
        {
            throw invalid_argument("Lastname isn't valid: The lastname must include only letters.");
        }
        lastname = _lastname;
        if (!check_date(_date))
        {
            throw invalid_argument("Date isn't valid: The date must be in the format GG/MM/AAAA.");
        }
        else
            date = _date;
        if (!verify_email(_email))
        {
            throw invalid_argument("Email isn't valid: The email must include @ and .");
        }
        email = _email;
        if (!only_ten_numbers(_phone))
        {
            throw invalid_argument("Phone number isn't valid: The phone number must include only (ten) numbers.");
        }
        phone = _phone;
    }
    // prints the information of the customer
    void info_customer()
    {
        cout << "The customer information is: " << endl;
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
        if (!check_name_lastname(_name))
        {
            throw invalid_argument("Name isn't valid: The name must include only letters.");
        }
        name = _name;
    }

    void set_lastname(string _lastname)
    {
        if (!check_name_lastname(_lastname))
        {
            throw invalid_argument("Lastname isn't valid: The lastname must include only letters.");
        }
        lastname = _lastname;
    }

    void set_date(string _date)
    {
        if (!check_date(_date))
        {
            throw invalid_argument("Date isn't valid: The date must be in the format GG/MM/AAAA.");
        }
        date = _date;
    }
    void set_email(string _email)
    {
        if (!verify_email(_email))
        {
            throw invalid_argument("Email isn't valid: The email must include @ and .");
        }
        email = _email;
    }
    void set_phone(string _phone)
    {
        if (!only_ten_numbers(_phone))
        {
            throw invalid_argument("Phone number isn't valid: The phone number must include only (ten) numbers.");
        }
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
        if (!check_date(_date))
        {
            throw invalid_argument("Date isn't valid: The date must be in the format GG/MM/AAAA.");
        }
        date = _date;
        outcome = _outcome;
        ptr_customer = _ptr_customer;
    }
    // Prints the interaction of the customer
    void info_interaction()
    {
        // cout << "The information of the interaction for customer " << ptr_customer->get_name() << " " << ptr_customer->get_lastname() << " is: " << endl;
        cout << "Type of Appointment: " << type_of_appointment << endl;
        cout << "Date: " << date << endl;
        cout << "Outcome: " << (outcome ? "good" : "not_good") << endl
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
    // Setters
    void set_type_of_appointment(string _type_of_appointment)
    {
        type_of_appointment = _type_of_appointment;
    }
    void set_date(string _date)
    {
        if (!check_date(_date))
        {
            throw invalid_argument("Date isn't valid: The date must be in the format GG/MM/AAAA.");
        }
        date = _date;
    }
    void set_outcome(bool _outcome)
    {
        outcome = _outcome;
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
        // Remove the interactions of the customer from the list. remove_if() method is incluse in std::list
        customer_interactions.remove_if(
            [customer](Interaction &interaction)
            {
                return interaction.find_interaction(*customer);
            });

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
        int flag = 0;
        for (auto iterator = customer_management.begin(); iterator != customer_management.end(); ++iterator)
        {
            flag++;
            cout << "\n"
                 << flag << ")" << endl;
            iterator->info_customer();
        }
        if (flag == 0)
        {
            cout << "\nThere aren't customers in the list!" << endl;
        }
    }
    // Prints the information of all the interactions for a customer
    void info_all_interactions(const Customer &customer)
    {
        // keyword "auto" --> to avoid the type of the iterator
        int flag = 0;
        for (auto iterator = customer_interactions.begin(); iterator != customer_interactions.end(); ++iterator)
        {
            if (iterator->find_interaction(customer))
            {
                flag++;
                if (flag == 1)
                {
                    cout << "The information of the interaction for customer " << iterator->get_customer()->get_name() << " " << iterator->get_customer()->get_lastname() << " is: " << endl;
                }
                cout << "\n"
                     << flag << ") interaction:" << endl;
                iterator->info_interaction();
            }
        }
        if (flag == 0)
        {
            cout << "\nThe customer does not have any interaction." << endl;
        }
    }
    // Check if a customer exists in the list
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

    // Recover a customer from the list
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
    cout << "\nPlease select an option: " << endl;
    cout << "1. Add a new customer" << endl;
    cout << "2. Add a new interaction for a specific customer" << endl;
    cout << "3. View all customers" << endl;
    cout << "4. View all interactions of a customer" << endl;
    cout << "5. Modify a customer" << endl;
    cout << "6. Delete a customer" << endl;
    cout << "7. Save and Exit" << endl;
    int option;
    cin >> option;
    return option;
}

// Function to clean the buffer
void clean_buffer()
{
    // Reset the error flags of the stream
    cin.clear();
    // Ignore the residual characters in the buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
// Function to insert the name of the customer
string insert_name_customer()
{
    string name;
    cout << "Please enter the name of the customer: " << endl;
    clean_buffer();
    cin >> name;
    name = fix_format(name);
    return name;
}
// Function to insert the lastname of the customer
string insert_lastname_customer()
{
    string lastname;
    cout << "Please enter the lastname of the customer: " << endl;
    clean_buffer();
    cin >> lastname;
    lastname = fix_format(lastname);
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
    cout << "Please enter the outcome of the appointment: [good/not_good]" << endl;
    cin >> outcome;
    return outcome == "good" ? true : false;
}

int main()
{
    cout << "\n\nWelcome to InsuraPro Solutions. We are dedicated to providing the highest quality customer management for insurance companies." << endl;
    Customer_Management cm;
    cout << "\nHave you already a CRM? [y/n]" << endl;
    string response;
    cin >> response;
    if (response == "y")
    {
        // Upload the file
        cout << "Great! Let's start by upload the file" << endl;
        // path without the file name
        char cwd[PATH_MAX];
        // full path where save the file
        string full_path;
        // file name
        string file_name = "file.txt";
        int index_while = 0;
        do
        {
            clean_buffer();
            cout << "Enter the path where you want to read the file: " << endl;
            // In my directory -> C:\\Users\\Utente\\Profession_AI\\Project_C++
            cin >> cwd;
            // Create the full path
            full_path = string(cwd) + "\\" + file_name;
            cout << "The full path is: " << full_path << endl;
            FILE *file;
            // Open the file in read mode and c_str() --> convert the string to a c-string (char array in C)
            file = fopen(full_path.c_str(), "r");
            if (file == NULL)
            {
                cout << "The file does not exist. Please enter a valid path." << endl;
                index_while = 1;
            }
            else
            {
                index_while = 0;
                char line[200];
                string name, lastname, date, email, phone, type_of_appointment, date_appointment, outcome;
                int number_interactions;
                // Read and insert in the lists  the information of the customers and interactions
                while (fgets(line, sizeof(line), file) != NULL)
                {
                    // Ignore the spaces at the beginning of the line
                    int i = 0;
                    while (line[i] == ' ' || line[i] == '\t')
                        i++;
                    if (!isdigit(line[i]))
                    {
                        // Read the information of the customer
                        istringstream iss(line);
                        iss >> name >> lastname >> date >> email >> phone;
                        Customer custom1(name, lastname, date, email, phone);
                        cm.add_customer(custom1);
                    }
                    else
                    {
                        // Read the information of the interaction
                        istringstream iss(line);
                        iss >> number_interactions >> name >> lastname >> type_of_appointment >> date_appointment >> outcome;
                        Customer *ptr_customer = cm.recover_customer(name, lastname);
                        Interaction inter1(type_of_appointment, date_appointment, outcome == "good" ? true : false, ptr_customer);
                        cm.add_interaction(inter1);
                    }
                }
                cout << "The file has been uploaded." << endl;
                fclose(file);
            }

        } while (index_while == 1);
    }
    cout << "\nLet's start!" << endl;
    int option;
    do
    {
        option = option_function();
        switch (option)
        {
        case 1:
        {
            // Add new customer to the list
            cout << "Please enter the customer information you want to add to the list: " << endl;
            string name = insert_name_customer();
            string lastname = insert_lastname_customer();
            string date = insert_date_customer();
            string email = insert_email_customer();
            string phone = insert_phone_customer();
            try
            {
                Customer custom1(name, lastname, date, email, phone);
                cm.add_customer(custom1);
                cout << "\nThe customer has been added to the list." << endl
                     << endl;
            }
            catch (const invalid_argument &e)
            {
                cout << "\n"
                     << e.what() << endl;
            }
            break;
        }
        case 2:
        {
            // Add new interaction to the list
            cout << "Please enter the information of the customer you want to add an interaction: " << endl;
            string name = insert_name_customer();
            string lastname = insert_lastname_customer();
            if (cm.exist_customer(name, lastname))
            {
                cout << "Please enter the information of the interaction for this customer: " << endl;
                string type_of_appointment = insert_type_of_appointment();
                string date = insert_date_interaction();
                bool outcome = insert_outcome_interaction();
                Customer *ptr_customer = cm.recover_customer(name, lastname);
                try
                {
                    Interaction inter1(type_of_appointment, date, outcome, ptr_customer);
                    cm.add_interaction(inter1);
                    cout << "\nThe interaction has been added to the list." << endl
                         << endl;
                }
                catch (const invalid_argument &e)
                {
                    cout << e.what() << endl;
                }
            }
            else
            {
                cout << "\nThe customer does not exist in the list." << endl
                     << endl;
            };

            break;
        }
        case 3:
        {
            // Print the information of all the customers
            cm.info_all_customers();
            break;
        }
        case 4:
        {
            // Print the information of all the interactions of a customer
            cout << "Please enter the information of the customer you want to see the interactions:" << endl;
            string name = insert_name_customer();
            string lastname = insert_lastname_customer();
            if (cm.exist_customer(name, lastname))
            {
                Customer *ptr_customer = cm.recover_customer(name, lastname);
                cm.info_all_interactions(*ptr_customer);
            }
            else
            {
                cout << "\nThe customer does not exist." << endl
                     << endl;
            };

            break;
        }
        case 5:
        {
            // Modify the information of a customer
            cout << "Please enter the customer information you want to modify: " << endl;
            string name = insert_name_customer();
            string lastname = insert_lastname_customer();
            if (cm.exist_customer(name, lastname))
            {
                Customer *ptr_customer = cm.recover_customer(name, lastname);
                cout << "What do you want to modify? [name, lastname, date, email, phone] " << endl;
                string response;
                cin >> response;
                try
                {
                    if (response == "name")
                    {
                        string new_name = insert_name_customer();
                        ptr_customer->set_name(new_name);
                        cout << "\nThe name has been modified with " << new_name << endl
                             << endl;
                    }
                    else if (response == "lastname")
                    {
                        string new_lastname = insert_lastname_customer();
                        ptr_customer->set_lastname(new_lastname);
                        cout << "\nThe lastname has been modified with " << new_lastname << endl
                             << endl;
                    }
                    else if (response == "date")
                    {
                        string new_date = insert_date_customer();
                        ptr_customer->set_date(new_date);
                        cout << "\nThe date of birth has been modified with " << new_date << endl
                             << endl;
                    }
                    else if (response == "email")
                    {
                        string new_email = insert_email_customer();
                        ptr_customer->set_email(new_email);
                        cout << "\nThe email has been modified with " << new_email << endl
                             << endl;
                    }
                    else if (response == "phone")
                    {
                        string new_phone = insert_phone_customer();
                        ptr_customer->set_phone(new_phone);
                        cout << "\nThe phone has been modified with " << new_phone << endl
                             << endl;
                    }

                    else
                    {
                        cout << "Please enter a valid option." << endl
                             << endl;
                    }
                }
                catch (const invalid_argument &e)
                {
                    cout << e.what() << endl;
                }
            }
            else
            {
                cout << "\nThe customer does not exist." << endl
                     << endl;
            }
            break;
        }
        case 6:
        {
            // Delete a customer from the list
            cout << "Please enter the customer information you want to delete:" << endl;
            string name = insert_name_customer();
            string lastname = insert_lastname_customer();
            if (cm.exist_customer(name, lastname))
            {
                Customer *ptr_customer = cm.recover_customer(name, lastname);
                cm.remove_customer(ptr_customer);
                cout << "\nThe customer and his interactions has been removed to the lists." << endl
                     << endl;
            }
            else
            {
                cout << "\nThe customer does not exist." << endl
                     << endl;
            }
            break;
        }
        case 7:
        {
            // Save the file and exit
            cout << "Saving the file..." << endl;
            clean_buffer();
            // path without the file name
            char cwd[PATH_MAX];
            // full path where save the file
            string full_path;
            // file name
            string file_name = "file.txt";
            int index_while = 0;
            do
            {
                cout << "Enter the path where you want to save the file: " << endl;
                // In my directory -> C:\\Users\\Utente\\Profession_AI\\Project_C++
                cin >> cwd;
                // Create the full path
                full_path = string(cwd) + "\\" + file_name;
                cout << "The full path is: " << full_path << endl;
                FILE *file;
                // Open the file in write mode
                file = fopen(full_path.c_str(), "w");
                if (file == NULL)
                {
                    cout << "Error. Please enter a valid path." << endl;
                    index_while = 1;
                }
                else
                {
                    index_while = 0;
                    // Loop over the list of customers
                    for (auto iterator = cm.customer_management.begin(); iterator != cm.customer_management.end(); ++iterator)
                    {
                        fprintf(file, "%s %s %s %s %s\n", iterator->get_name().c_str(), iterator->get_lastname().c_str(), iterator->get_date().c_str(), iterator->get_email().c_str(), iterator->get_phone().c_str());
                        // Loop over the list of interactions
                        int number_interactions = 1;
                        for (auto iterator2 = cm.customer_interactions.begin(); iterator2 != cm.customer_interactions.end(); ++iterator2)
                        {
                            if (iterator2->get_customer()->get_name() == iterator->get_name() && iterator2->get_customer()->get_lastname() == iterator->get_lastname())
                            {
                                bool outcome = iterator2->get_outcome();
                                string outcome_str = outcome ? "good" : "not_good";
                                fprintf(file, "\t%d %s %s %s %s %s\n", number_interactions, iterator2->get_customer()->get_name().c_str(), iterator2->get_customer()->get_lastname().c_str(), iterator2->get_type_of_appointment().c_str(), iterator2->get_date().c_str(), outcome_str.c_str());
                                number_interactions++;
                            }
                        }
                    }
                    cout << "Thank you for using InsuraPro Solutions. Have a great day!" << endl;
                    fclose(file);
                }
            } while (index_while == 1);
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