#include <iostream>
#include <vector>

using namespace std;

//*********************************************CLASS PRE-DECLARATIONS***************************************************
class Artwork;
class Artist;
class Customer;
//**********************************************CLASS DECLARATIONS******************************************************
//*********************************************Gallery class************************************************************

class Gallery
{
	string galleryName;
    int capacity =0; //done
    double currBudget; //used to keep track of the current profit
public:
    vector<Artwork> Artworkl;
    vector<Artist> Artistl;
    vector<Customer> Customerl;

    string getGalleryName(){return galleryName;}
    int getCapacity(){return capacity;}
    double getCurrBudget(){ return  currBudget;}
    void printAll(int a);
    void increaseCapacity(); //Used in main
    Gallery(string name, double budget);
    ~Gallery();
    bool isAllSold(); //checks availability of all using a counter

    int getNumOfArtworks(){
        int num=0;
        vector<Artwork>::iterator it;
        for(it=Artworkl.begin(); it!=Artworkl.end(); ++it) {
            num++;
        }
        return num;
    }///////////
    //Artworks//
    void printAllArtwork();
    void addArtwork(string title1, string name1, double price1);
    void removeArtwork();
    int returnAvailability(string a);

    //Artists//
    void removeArtist();
    void printAllArtist();

    //Customers//
    void printAllCustomer();
    void addCustomer(string name, string IntWork, double MoneyOwned);/////
    void removeCustomer();

};

//**********************************************Artwork class***********************************************************
class Artwork
{
    string artistName = "";
    string artworkTitle ="";
    double price =0;
    int availability =1;
public:
    string getArtistNameA(){return artistName;}
    string getArtworkTitleA(){return artworkTitle;}
    int getAvailability(){return availability;}
    void printArtwork();
    double getPrice(){return price;}
    Artwork(string a, string b, double c);
	~Artwork();
    void makeAvailabilityZ(){this->availability = 0;}

    friend Gallery;
};

//*************************************************Artist class*********************************************************
class Artist
{
    string artistName = "";
    string artworkTitle ="";
    double profit =0;
public:
    Artist(string name ="", string title="");
    ~Artist();
    void printArtist();
    void increaseProfit(double val) { this->profit += (0.6*val); } //used by customer's addTo
    string getArtworkTitle(){return artworkTitle;}
};

//**********************************Customer class*****************************************************
class Customer
{
private:
    string customerName;
    string interestedWork;
    double moneyOwned;

public:
    Customer(string a="", string b="", double c=0);
    void printCustomer();
    string getCustomerName(){return customerName;}
    string getInterestedWork(){return interestedWork;}
    ~Customer();

    friend Gallery;
};

//************************************************METHODS***************************************************************
//**********************************************************************************************************************

//*********************************************Gallery Methods**********************************************************
//*********************************************constructor**************************************************************
Gallery::Gallery(string name = "Gallery", double budgetInput = 750)
{
    this->galleryName = name;
    if(budgetInput < 400){
    cout<<"Sorry, the budget is too little, the gallery cannot run" <<endl;
    }
    else if((400<=budgetInput) && (budgetInput<=2000)){
        double budgetCal;
        budgetCal = budgetInput/2000;
        double Cal = 15 * budgetCal;
        this->capacity = int(Cal);
        this->currBudget = budgetInput - (budgetCal*2000);}
    else{
        this->capacity = 15;
        this->currBudget = (budgetInput-2000);}
    cout << "Creating a Gallery of name: " << this->galleryName << endl;
    cout<<"Budget: " << this->currBudget<<endl;
    cout<<"Number of Artworks: "<< this->capacity<<endl;
}

//*********************************************destructor***************************************************************
Gallery::~Gallery()
{
}

//****************************************increaseCapacity*************************************************************
//if the Gallery has enough money, it's artworks capacity will increase but only once
void Gallery::increaseCapacity() {
    if(this->capacity<15)
        if(((this->currBudget)/2000)>=1){
            double a =15*((this->currBudget)/2000);
            this->capacity= int(a);
            this->currBudget-=2000;
            cout <<"Capacity increased! new capacity: "<< this->capacity << endl;}
        else{cout <<"Sorry, the Gallery hasn't earned enough yet:(" <<endl;}
    else{cout <<"The capacity of artworks has already reached the maximum amount" <<endl;}
}

//*************************************************print****************************************************************
//prints out the information about a Gallery as well as it's contents
void Gallery::printAll(int a)
{
    switch(a)
    {
        case 1:
            printAllArtist();
            break;
        case 2:
            printAllArtwork();
            break;
        case 3:
            printAllCustomer();
            break;
        default:
            cout<<" ";
            break;
    }
}

int Gallery::returnAvailability(string a) {
    {
        int b=0;
        vector<Artwork>::iterator it;
        for(it=Artworkl.begin(); it!=Artworkl.end(); it++ )
            if(it->getArtworkTitleA() == a)
            {
                b=it->getAvailability();
            }
        return b;
    }
}

//**********************************************addArtwork**************************************************************

void Gallery::addArtwork(string title1, string name1, double price1) {
    if(getNumOfArtworks()<getCapacity()){
        Artwork a(title1, name1, price1);
        Artworkl.push_back(a);

        Artist b(name1, title1);
        Artistl.push_back(b);
    }
}

//**********************************************removeArtwork**************************************************************

void Gallery::removeArtwork(){
    cout<< "What would you like to remove? ";
    string toBeRemoved;
    cin >> toBeRemoved;
    vector<Artwork>::iterator it;
    int i=0;
    for(it=Artworkl.begin(); it!=Artworkl.end(); it++ )
    {
        if(it->getArtworkTitleA() == toBeRemoved)
        {
            Artworkl.erase(Artworkl.begin()+i);
        }
        i++;
    }
}

//************************************************printAllArtwork**********************************************************
void Gallery::printAllArtwork(){
    vector<Artwork>::iterator it;
    for(it=Artworkl.begin(); it!=Artworkl.end(); ++it)
    {
        it->printArtwork();
    }
}

//*********************************************printAllArtist**************************************************************
void Gallery::printAllArtist() {
    vector<Artist>::iterator it;
    for(it=Artistl.begin(); it!=Artistl.end(); ++it)
    {
        it->printArtist();
    }
}

//*********************************************RemoveArtist**************************************************************
void::Gallery::removeArtist() {
    vector<Artwork>::iterator it;
    vector<Artist>::iterator itt;
    cout<<"what artist would you like to remove?: "<<endl;
    string toBeRemoved;
    cin>>toBeRemoved;
    int i=0;
    for(it=Artworkl.begin(); it!=Artworkl.end(); ++it)
    {
        if(it->getArtworkTitleA()==toBeRemoved)
        {Artworkl.erase(Artworkl.begin()+(i));}
        i++;
    }
    i=0;
    for(itt=Artistl.begin(); itt!=Artistl.end(); ++itt)
    {
        if(itt->getArtworkTitle() == toBeRemoved)
        {Artistl.erase(Artistl.begin()+(i));}
        i++;
    }

}

//*********************************************addCustomer**************************************************************
void Gallery::addCustomer(string name, string IntWork, double MoneyOwned) {
    //when adding, modify availability, modify profit, modify gallery budget, call extension function
    //I need to have different functions which only add customer, which only add existing customer
    /*
    cout<<"How many customers would you like to add?" <<endl;
    int numOfCustomers;
    cin >> numOfCustomers;
    Customer *customer = new Customer[numOfCustomers]();
    for(int i =0; i < numOfCustomers; i++){
    */
    Customer a(name, IntWork, MoneyOwned);
    Customerl.emplace_back(a);

    vector<Artwork>::iterator it;
    vector<Artist>::iterator ita;

    if (isAllSold()) {
        cout << "Exhibition now over" << endl;
        exit(0);
    }
    double sum=0;
    for(it=Artworkl.begin(); it!=Artworkl.end(); ++it) {
        if ((IntWork == it->getArtworkTitleA())&&(it->getAvailability())){
            it->makeAvailabilityZ(); //modifying availability
            sum += it->getPrice();
            for (ita = Artistl.begin(); ita != Artistl.end(); ++ita) {
                if (IntWork == ita->getArtworkTitle())
                    ita->increaseProfit(it->getPrice());//modifying profit
            }
        }
    }
    this->currBudget+=(0.4*sum);
}

//*********************************************RemoveCustomer**************************************************************
void Gallery::removeCustomer() {
    cout<< "Who would you like to remove?";
    string toBeRemoved;
    cin >> toBeRemoved;
    int i=0;
    vector<Customer>::iterator it;
    for(it=Customerl.begin(); it!=Customerl.end(); ++it)
    {
        if(it->getCustomerName() == toBeRemoved)
        {Customerl.erase(Customerl.begin()+(i+1));}
        i++;
    }
}

//*********************************************printAllCustomer**************************************************************
void Gallery::printAllCustomer() {
    vector<Customer>::iterator it;
    for(it=Customerl.begin(); it!=Customerl.end(); ++it)
    {
        it->printCustomer();
    }
}

bool Gallery::isAllSold() {
    vector<Artwork>::iterator it;
    int availabilityCheck=0;
    for(it=Artworkl.begin(); it!=Artworkl.end(); ++it)
    {
        if(it->getAvailability()==0)
            availabilityCheck++;
    }
    if(availabilityCheck==capacity)
        return true;
    else
        return false;
}

Artwork::Artwork(string a, string b, double c )
{

    this->artworkTitle = a;
    this->artistName = b;
    this->price = c;
    this->availability = 1;
}
//*****************************************************destructor*******************************************************
Artwork::~Artwork()
{
}

//************************************************print**********************************************************
void Artwork::printArtwork() {
    cout<<"Artwork title: " << this->artworkTitle<<endl;
    cout<<"Artist name: " << this->artistName <<endl;
    cout <<"Price of artwork: " <<this->price <<endl;
    string isSold = "Sold";
    if(this->availability ==1){
        isSold = "Available";
    }
    cout<< "Artwork state: " << isSold<<endl;
}

//*********************************************Artist Methods*************************************************************
//*********************************************constructor**************************************************************
Artist::Artist(string name, string title) {
    this->artistName = name;
    this->artworkTitle = title;
    this->profit = 0;
}

//*********************************************destructor**************************************************************
Artist::~Artist() {
}

//*********************************************printArtist**************************************************************
void Artist::printArtist() {
    cout<<"Artist name: " << this->artistName<<endl;
    cout<<"Their work: " << this->artworkTitle <<endl;
    cout <<"Profit: " <<this->profit <<endl;
}

//*********************************************Customer Methods********************************************************
//*********************************************constructor**************************************************************
Customer::Customer(string a , string b, double c) {

    this->customerName = a;
    this->interestedWork = b;
    this->moneyOwned = c;
}

//*********************************************destructor**************************************************************
Customer::~Customer() {
    //cout<<"Deleting the customer of name: "<<customerName;
}

//*********************************************printCustomer**************************************************************
void Customer::printCustomer() {
    cout<<"Customer name: " << this->customerName<<endl;
    cout<<"Interested work: " << this->interestedWork <<endl;
    cout <<"Money they own: " <<this->moneyOwned<<endl;
}


//**********************************Test class*****************************************************

class Test{
public:
    int test1();
    int test2();
    int test3();
};

int Test::test1() {
    cout<<"\n///////////Testing if the program prevents number of artworks exceeding the capacity///////////"<<endl;
    cout<<endl;
    Gallery a("Test1Gallery", 400);
    a.addArtwork("title1", "artist1", 50);
    a.addArtwork("title2", "artist2", 60);
    a.addArtwork("title3", "artist3", 70);
    a.addArtwork("title4", "artist4", 80);
    if((a.getCapacity())==(a.getNumOfArtworks())){
        cout<<"!!!Test Passed!!!"<<endl;
        cout<<"Number of artworks: "<<a.getNumOfArtworks()<<endl;
        a.printAll(2);
        return 0;
    }
    else{
        cout<<"!!!Test failed!!!"<<endl;
        return 1;
    }
}
int Test::test2() {
    cout<<"\n///////////Testing if the program prevents number of artworks exceeding the capacity///////////"<<endl;
    cout<<endl;
    Gallery b("Test2Gallery", 400);
    b.addArtwork("title1", "artist1", 50);
    b.addArtwork("title2", "artist2", 60);
    if((b.getCapacity())>=(b.getNumOfArtworks())){
        cout<<"!!!Test Passed!!!"<<endl;
        cout<<"Number of artworks: "<<b.getNumOfArtworks()<<endl;
        b.printAll(2);
        return 0;
    }
    else{
        cout<<"!!!Test failed!!!"<<endl;
        return 2;
    }
}
int Test::test3(){
    cout<<endl;
    cout<<"\n///////////Testing if it is possible to purchase an artwork///////////"<<endl;
    cout<<endl;
    Gallery c("Test3Gallery", 500);
    c.addArtwork("title1", "artist1", 60);
    c.addArtwork("title2", "artist2", 60);
    c.addArtwork("title3", "artist3", 70);
    c.addArtwork("title4", "artist4", 80);
    c.addCustomer("customer1", "title2", 120);
    c.addCustomer("customer1", "title2", 200);
    int b=0;
    b=c.returnAvailability("title2");
    if(b==0){
        cout<<"!!!Test Passed!!!"<<endl;
        c.printAll(2);
        cout<<"Customer purchased one artwork"<<endl;
        return 0;
    }
    else{
        cout<<"!!!Test failed!!!"<<endl;
        return 3;
    }
}

//**********************************userInterface class*****************************************************
class userInterface
{
public:
    void addCustomer(Gallery &a){
        cout<<"Enter customer name: ";
        string name;
        cin>>name;
        cout<<"Enter customer Interested work: ";
        string IntWork;
        cin>>IntWork;
        cout<<"Enter Money Owned: ";
        double MoneyOwned;
        cin>>MoneyOwned;
        a.addCustomer(name,IntWork, MoneyOwned);
    }
    void addArtwork(Gallery &a){
        cout<<"Enter title: ";
        string title1;
        cin>>title1;
        cout<<"Enter name: ";
        string name1;
        cin>>name1;
        cout<<"Enter price : ";
        double price1;
        cin>>price1;
        a.addArtwork(title1, name1, price1);
    }
    void printAll(Gallery &a){
        cout<< "---------INFORMATION ON GALLERY-------------"<<endl;
        cout << "Name of the Gallery: " << a.getGalleryName() << endl;
        cout << "Budget: " << a.getCurrBudget() << endl;
        cout << "Number of artworks: " << a.getCapacity() <<endl;

        //make selection of display of information available
        cout<<"If you want to view the information on artists, enter 1"<<endl;
        cout<<"For the information on artworks, enter 2"<<endl;
        cout<<"For the information on customers, enter 3"<<endl;
        int b;
        cin>>b;
        a.printAll(b);
    }
};


//**********************************************************************************************************************
//**************************************************MAIN****************************************************************
//**********************************************************************************************************************


int main()
{
    Test t = Test();

    int errcode1 = t.test1();
    int errcode2 = t.test2();
    int errcode3 = t.test3();
    cout<<"\n\n";
    int num;
    if(errcode1!=0){
        cout<<"Error code: "<<errcode1<<endl;
    }
    if(errcode1==0){
        num++;
    }
    if(errcode2!=0){
        cout<<"Error code: "<<errcode2<<endl;
    }
    if(errcode2==0){
        num++;
    }
    if(errcode3!=0){
        cout<<"Error code: "<<errcode3<<endl;
    }
    if(errcode3==0){
        num++;
    }
    cout<<"Number of tests passed: "<<num<<endl;

    cout<<"Testing User Interface"<<endl;
    Gallery b("ArtGallery", 700);
    b.addArtwork("title1", "artist1", 50);
    b.addArtwork("title2", "artist2", 70);

    userInterface u;
    u.addArtwork(b);
    u.addCustomer(b);
    u.addCustomer(b);
    u.printAll(b);
    b.removeCustomer();
    b.removeArtwork();
    return 0;
}

