#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <limits>
#include <windows.h>
using namespace std;

enum Role
{
    Admin,
    Staff,
    Customer
};

struct product
{
    string name;
    int price;
    int quantity;
};

struct member
{
    string name;
    int age;
    string address;
    string phone;
    string email;
    Role role;
    string password;
};

class Product
{
public:
    vector<product> products;

    void LoadProductsFromFile()
    {
        ifstream file("products.txt");
        product p;
        while (file >> p.name >> p.price >> p.quantity)
        {
            products.push_back(p);
        }
        file.close();
    }

    void SaveProductsToFile()
    {
        ofstream file("products.txt");
        for (const auto &p : products)
        {
            file << p.name << " " << p.price << " " << p.quantity << endl;
        }
        file.close();
    }

    void AddProduct()
    {
        product p;
        cout << "Enter product name: ";
        getline(cin >> ws, p.name);
        cout << "Enter price: ";
        while (!(cin >> p.price))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Enter price again: ";
        }
        cout << "Enter quantity: ";
        while (!(cin >> p.quantity))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Enter quantity again: ";
        }
        products.push_back(p);
        cout << "Product added successfully!\n";
    }

    void ShowAllProducts()
    {
        if (products.empty())
        {
            cout << "No products found!\n";
            return;
        }
        cout << left << setw(15) << "Name" << setw(10) << "Price" << "Quantity\n";
        cout << string(30, '-') << endl;
        for (const auto &p : products)
        {
            cout << setw(15) << p.name << setw(10) << p.price << p.quantity << endl;
        }
    }

    void DeleteProduct()
    {
        string name;
        cout << "Enter product name to delete: ";
        getline(cin >> ws, name);
        auto it = find_if(products.begin(), products.end(), [&](const product &p)
                          { return p.name == name; });
        if (it == products.end())
        {
            cout << "Product not found!\n";
            return;
        }
        products.erase(it);
        cout << "Product deleted successfully!\n";
    }

    void BuyProduct()
    {
        string name;
        cout << "Enter product name to buy: ";
        getline(cin >> ws, name);
        auto it = find_if(products.begin(), products.end(), [&](const product &p)
                          { return p.name == name; });
        if (it == products.end())
        {
            cout << "Product not found!\n";
            return;
        }
        int quantity;
        cout << "Enter quantity: ";
        while (!(cin >> quantity) || quantity > it->quantity)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Enter a valid quantity (max " << it->quantity << "): ";
        }
        it->quantity -= quantity;
        cout << "Purchase successful! Remaining stock: " << it->quantity << endl;
    }
};

class People
{
    vector<member> members;
    Product product;

public:
    void LoadMembersFromFile()
    {
        ifstream file("members.txt");
        member m;
        string roleStr;
        while (file >> m.name >> m.age >> m.address >> m.phone >> m.email >> roleStr >> m.password)
        {
            if (roleStr == "0")
                m.role = Admin;
            else if (roleStr == "1")
                m.role = Staff;
            else
                m.role = Customer;
            members.push_back(m);
        }
        file.close();
    }

    void SaveMembersToFile()
    {
        ofstream file("members.txt");
        for (const auto &m : members)
        {
            file << m.name << " " << m.age << " " << m.address << " " << m.phone << " " << m.email << " "
                 << static_cast<int>(m.role) << " " << m.password << endl;
        }
        file.close();
    }

    int countAdmins()
    {
        return count_if(members.begin(), members.end(), [](const member &m)
                        { return m.role == Admin; });
    }

    void login()
    {
        string name, password;
        cout << "Enter your name: ";
        getline(cin >> ws, name);
        cout << "Enter your password: ";
        getline(cin, password);

        auto it = find_if(members.begin(), members.end(), [&](const member &m)
                          { return m.name == name && m.password == password && m.role == Admin; });

        if (it != members.end())
        {
            cout << "Welcome Master " << name << "!\n";
            int choice;
            while (true)
            {
                cout << "\nWhat do you want to do?\n";
                cout << "1. Add member\n2. Show all products\n3. Add product\n";
                cout << "4. Buy product\n5. Delete product\n6. Show all members\n";
                cout << "7. Delete member\n8. Logout\n";
                cout << "Enter choice: ";
                cin >> choice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (choice)
                {
                case 1:
                    AddMember();
                    break;
                case 2:
                    product.ShowAllProducts();
                    break;
                case 3:
                    product.AddProduct();
                    break;
                case 4:
                    product.BuyProduct();
                    break;
                case 5:
                    product.DeleteProduct();
                    break;
                case 6:
                    ShowAllMembers();
                    break;
                case 7:
                    DeleteMember();
                    break;
                case 8:
                    product.SaveProductsToFile();
                    SaveMembersToFile();
                    cout << "Goodbye!\n";
                    return;
                default:
                    cout << "Invalid choice! Try again.\n";
                }
            }
        }
        else
        {
            cout << "Invalid username, password, or insufficient privileges!\n";
        }
    }

    void Staf()
    {
        string name, password;
        cout << "Enter your name: ";
        getline(cin >> ws, name);
        cout << "Enter your password: ";
        getline(cin, password);

        auto it = find_if(members.begin(), members.end(), [&](const member &m)
                          { return m.name == name && m.password == password && m.role == Staff; });

        if (it != members.end())
        {
            cout << "Welcome Staff " << name << "!\n";
            int choice;
            while (true)
            {
                cout << "\nChoose an option:\n1. Add Product\n2. Show All Products\n";
                cout << "3. Delete Product\n4. Buy Product\n5. Logout\n";
                cin >> choice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (choice)
                {
                case 1:
                    product.AddProduct();
                    break;
                case 2:
                    product.ShowAllProducts();
                    break;
                case 3:
                    product.DeleteProduct();
                    break;
                case 4:
                    product.BuyProduct();
                    break;
                case 5:
                    product.SaveProductsToFile();
                    cout << "Goodbye!\n";
                    return;
                default:
                    cout << "Invalid choice! Try again.\n";
                }
            }
        }
        else
        {
            cout << "Invalid username or password!\n";
        }
    }

    void Customerr()
    {
        int choice;
        cout << "Welcome Customer!\n";
        while (true)
        {
            cout << "\nChoose an option:\n1. Show All Products\n2. Buy Product\n3. Logout\n";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (choice)
            {
            case 1:
                product.ShowAllProducts();
                break;
            case 2:
                product.BuyProduct();
                break;
            case 3:
                product.SaveProductsToFile();
                cout << "Goodbye!\n";
                return;
            default:
                cout << "Invalid choice! Try again.\n";
            }
        }
    }

    void AddMember(member *defaultMember = nullptr)
    {
        member m;
        int roleChoice;

        if (defaultMember)
        {
            m = *defaultMember;
        }
        else
        {
            cout << "Enter name: ";
            getline(cin >> ws, m.name);
            cout << "Enter age: ";
            while (!(cin >> m.age))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Enter age again: ";
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter address: ";
            getline(cin, m.address);
            cout << "Enter phone: ";
            getline(cin, m.phone);
            cout << "Enter email: ";
            getline(cin, m.email);
            cout << "Enter password: ";
            getline(cin, m.password);

            cout << "Select role: \n1. Admin\n2. Staff\n3. Customer\nEnter choice: ";
            cin >> roleChoice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (roleChoice)
            {
            case 1:
                if (countAdmins() >= 3)
                {
                    cout << "Admin limit reached (3 maximum)!\n";
                    return;
                }
                m.role = Admin;
                break;
            case 2:
                m.role = Staff;
                break;
            case 3:
                m.role = Customer;
                break;
            default:
                cout << "Invalid choice! Defaulting to Customer.\n";
                m.role = Customer;
            }
        }
        members.push_back(m);
        if (!defaultMember)
        {
            cout << "Member added successfully!\n";
        }
    }

    void ShowAllMembers()
    {
        if (members.empty())
        {
            cout << "No members found!\n";
            return;
        }
        cout << left << setw(15) << "Name" << setw(5) << "Age" << setw(20) << "Address"
             << setw(15) << "Phone" << setw(20) << "Email" << "Role\n";
        cout << string(75, '-') << endl;
        for (const auto &m : members)
        {
            string roleStr = (m.role == Admin) ? "Admin" : (m.role == Staff) ? "Staff"
                                                                             : "Customer";
            cout << setw(15) << m.name << setw(5) << m.age << setw(20) << m.address
                 << setw(15) << m.phone << setw(20) << m.email << roleStr << endl;
        }
    }

    void DeleteMember()
    {
        string name;
        cout << "Enter member name to delete: ";
        getline(cin >> ws, name);
        auto it = find_if(members.begin(), members.end(), [&](const member &m)
                          { return m.name == name; });
        if (it == members.end())
        {
            cout << "Member not found!\n";
            return;
        }
        members.erase(it);
        cout << "Member deleted successfully!\n";
    }
};

int main()
{
    People people;
    Product products;

    people.LoadMembersFromFile();
    if (people.countAdmins() == 0)
    {
        member defaultAdmin;
        defaultAdmin.name = "admin";
        defaultAdmin.age = 30;
        defaultAdmin.address = "Default";
        defaultAdmin.phone = "000000";
        defaultAdmin.email = "admin@email.com";
        defaultAdmin.role = Admin;
        defaultAdmin.password = "admin123";
        people.AddMember(&defaultAdmin);
        people.SaveMembersToFile();
        cout << "Default admin created: Name: admin, Password: admin123\n";
    }
    products.LoadProductsFromFile();

    int choice;
    while (true)
    {
        cout << "\nChoose an option:\n";
        cout << "1. Admin Login\n2. Staff Login\n3. Customer\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            people.login();
            break;
        case 2:
            people.Staf();
            break;
        case 3:
            people.Customerr();
            break;
        case 4:
            products.SaveProductsToFile();
            people.SaveMembersToFile();
            cout << "All data saved successfully. Program terminated.\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}