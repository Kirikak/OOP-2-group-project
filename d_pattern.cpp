#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cassert> 
class housePart{
public:
  enum hPart{Sitting, Bedroom, Washroom, Kitchen, NPARTS};
  housePart(hPart id) : id(id){}
  friend std::ostream&
  operator<<(std::ostream&, const housePart&);
private:
  static std::string parts[NPARTS];
  hPart id;
};
std::string housePart::parts[NPARTS] = {"Sitting","Bedroom", "washroom", "Kitchen"};
std::ostream&
operator<<(std::ostream& out, const housePart& keja){
  return out << keja.parts[keja.id];
}
class Home{
  std::vector<housePart*> parts;
public:
  ~Home();
  void addPart(housePart* part){ parts.push_back(part); }
  friend std::ostream&
  operator<<(std::ostream&, const Home&);
};
std::ostream&
operator<<(std::ostream& out, const Home& Home){
  out << " has [";
  for(auto part: Home.parts) out << (*part) << ' ';
  return out << ']';
}
class HomeBuilder{ //!NOTE: the `builder' class.
protected:
  Home* keja;
public:
  HomeBuilder(): keja(0){}
  void createHome(){ keja = new Home; }
  virtual void buildSitting() = 0;
  virtual void buildBedroom() = 0;
  virtual void buildWashroom() = 0;
   virtual void buildKitchen() = 0;
  virtual std::string gethmName() const = 0;
  Home* gethm(){
    Home* newkeja = keja;
    keja = 0;
    return newkeja;
  }
};
class HutBuilder : public HomeBuilder{
public:
  void buildSitting(){
    keja->addPart(new housePart(housePart::Sitting));
  }
  void buildBedroom(){}  //!NOTE: cups without lids
  void buildWashroom(){}
  void buildKitchen() {
      keja->addPart(new housePart(housePart::Kitchen));
      }
  std::string gethmName() const{
    return " Hut ";
  }
};
class BrickBuilder : public HomeBuilder{
  void buildSitting(){
    keja->addPart(new housePart(housePart::Sitting));
  }
  void buildBedroom(){
    keja->addPart(new housePart(housePart::Bedroom));
  }
  void buildWashroom(){
    keja->addPart(new housePart(housePart::Washroom));
  }
  void buildKitchen(){
    keja->addPart(new housePart(housePart::Kitchen));
  }
  std::string gethmName() const{
    return "Brick";
  }
};
class Contructor{
  HomeBuilder* builder;
public:
  Contructor() : builder(0){}
  void setBuilder(HomeBuilder* builder){
    this->builder = builder;
  }
  void make(){
    assert(builder);
    builder->createHome();
    builder->buildSitting();
    builder->buildBedroom();
    builder->buildWashroom();
    builder->buildKitchen();
  }
};
using namespace std;
Home *
makeAHouse(Contructor& contructor, HomeBuilder* pattern){
  contructor.setBuilder(pattern);
  contructor.make();
  Home* keja = pattern->gethm();
  cout << "Made a " << pattern->gethmName() << endl;
  return keja;
}
int main(){
  map<string, int> home;
  home["Hut"] = 30;
  home["Brick"] = 10;

  vector<Home*> containers;
  BrickBuilder* bb = new BrickBuilder;
  HutBuilder* hb = new HutBuilder;
  Contructor contructor;
  map<string, int>::const_iterator cit = home.begin();
  while(cit != home.end()){
    HomeBuilder* pattern;
    if(cit->first == "Hut")
      pattern = hb;
    else if(cit->first == "Brick")
      pattern = bb;
    for(int i = 0; i < cit->second; ++i)
      containers.push_back(makeAHouse(contructor, pattern));
    ++cit;
  }
  
  int i = 0;
  for(auto container: containers)
    cout << "Container " << i++
         << " " << (*container) << endl;
}


