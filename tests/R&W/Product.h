#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
  Product();
  Product(int id, std::string name, double price);
  ~Product() = default;
  std::string toString();
  int getId();
  void setId(int id);
  double getPrice();
  void setPrice(double price);
  std::string getName();
  void setName(std::string name);
private:
  double price_;
  std::string name_;
  int id_;
};

#endif // !PRODUCT_H
