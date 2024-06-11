#include "Product.h"
#include <sstream>
#include <string>

Product::Product(int id, std::string name, double price) : id_(id), name_(name), price_(price) {  }

Product::Product() { Product(0,"",0); }

void Product::setId(int id) { id_ = id; }

int Product::getId() { return id_; }

void Product::setName(std::string name) { name_ = name; }

std::string Product::getName() { return name_; }

void Product::setPrice(double price) { price_ = price; }

double Product::getPrice() { return price_; }

std::string Product::toString() {
  std::ostringstream oss;
  oss << "Product (id="<<id_<<", name="<<name_<<", price="<<price_<<")";
  return oss.str();
}
