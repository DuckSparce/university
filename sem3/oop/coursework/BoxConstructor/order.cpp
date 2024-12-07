#include "order.h"

#include "exceptions.h"
#include <vector>
#include <iostream>

std::unordered_map<Material, double> Order::prices = { {CorrugatedCardboard, 0.99},
                                                       {SolidCardboard, 2.49},
                                                       {Wood, 8.99},
                                                       {Biodegradable, 3.99},
                                                       {Plastic, 1.79},
                                                       {Undefined, NAN} };

Order::Order() : length(10), width(10), height(10), material(Undefined), count(1) {}

Order::Order(unsigned int len, unsigned int wid, unsigned int hei, Material mat, unsigned int cnt)
    : length(len), width(wid), height(hei), material(mat), count(cnt) {}

Order::Order(const Order &other)
    : length(other.length)
    , width(other.width)
    , height(other.height)
    , material(other.material)
    , count(other.count) {}

Order::Order(Order &&other) noexcept
    : length(other.length)
    , width(other.width)
    , height(other.height)
    , material(other.material)
    , count(other.count) {
    other.length = 0;
    other.width = 0;
    other.height = 0;
    other.material = Undefined;
    other.count = 0;
}

Order& Order::operator=(const Order &other) {
    if (&other == this) {
        return *this;
    }
    
    length = other.length;
    width = other.width;
    height = other.height;
    material = other.material;
    count = other.count;
    
    return *this;
}

unsigned int Order::getLength() const {
    return length;
}

void Order::setLength(unsigned int newLength) {
    length = newLength;
}

unsigned int Order::getWidth() const {
    return width;
}

void Order::setWidth(unsigned int newWidth) {
    width = newWidth;
}

unsigned int Order::getHeight() const {
    return height;
}

void Order::setHeight(unsigned int newHeight) {
    height = newHeight;
}

Material Order::getMaterial() const {
    return material;
}

void Order::setMaterial(Material newMaterial) {
    material = newMaterial;
}

unsigned int Order::getCount() const {
    return count;
}

void Order::setCount(unsigned int newCount) {
    count = newCount;
}

double Order::getPrice(Material material) {
    if (material == Undefined) {
        throw InvalidMaterialException("Матеріал коробки невизначений.");
    }

    return prices.at(material);
}

void Order::setPrice(Material material, double newPrice) {
    prices.at(material) = newPrice;
}

double Order::getMaterialCost() {
    double area = 2 * (length * width + length * height + width * height) / 10000.0;
    return std::ceil(area * getPrice(material) * count * 100) / 100;
}

double Order::getCost() {
    double orderSalaries = getMaterialCost() * 0.1;
    double orderAmortization = getMaterialCost() * 0.13567;
    double orderTax = (getMaterialCost() + orderSalaries + orderAmortization) * 0.21;
    cost = std::ceil((getMaterialCost() + orderSalaries + orderAmortization + orderTax) * 100) / 100;

    return cost;
}

void Order::setCost(double newCost) {
    cost = newCost;
}

Order& Order::operator=(Order&& other) noexcept {
    if (&other == this) {
        return *this;
    }
    
    length = other.length;
    width = other.width;
    height = other.height;
    material = other.material;
    count = other.count;
    
    other.length = 0;
    other.width = 0;
    other.height = 0;
    other.material = Undefined;
    other.count = 0;
    
    return *this;
}

std::string materialToString(Material material) {
    switch (material) {
    case CorrugatedCardboard: return "Гофрокартон"; break;
    case SolidCardboard: return "ПалітурнийКартон"; break;
    case Wood: return "Деревина"; break;
    case Biodegradable: return "БіорозкладнийМатеріал"; break;
    case Plastic: return "Пластик"; break;
    default: throw InvalidMaterialException("Матеріал коробки невизначений.");
    }
}

Material stringToMaterial(const std::string& str) {
    if (str == "Гофрокартон") return Material::CorrugatedCardboard;
    else if (str == "ПалітурнийКартон") return Material::SolidCardboard;
    else if (str == "Деревина") return Material::Wood;
    else if (str == "БіорозкладнийМатеріал") return Material::Biodegradable;
    else if (str == "Пластик") return Material::Plastic;
    throw WrongFormatException("Матеріалу " + str + ", зчитаного з файлу, не існує");
}

std::ostream& operator<<(std::ostream& os, const Order& order) {
    os << order.length << 'x' << order.width << 'x' << order.height << '\t';
    std::string material = materialToString(order.material);
    os << material;

    if (material == "Пластик") {
        os << "\t\t";
    } else if (material == "Деревина" || material == "Гофрокартон") {
        os << "\t";
    }

    os << "\t" << order.count;
    return os;
}

std::istream& operator>>(std::istream& is, Order& order) {
    std::string materialStr;
    char x;

    if (is.eof()) {
        return is;
    }

    if (is >> order.length >> x >> order.width >> x >> order.height >> materialStr >> order.count) {
        order.material = stringToMaterial(materialStr);

        if (order.length > 150 | order.length < 10) {
            throw WrongFormatException("Довжина коробки повинна бути між 10 і 150");
        } else if (order.width > 150 | order.width < 10) {
            throw WrongFormatException("Товщина коробки повинна бути між 10 і 150");
        } else if (order.height > 150 | order.height < 10) {
            throw WrongFormatException("Висота коробки повинна бути між 10 і 150");
        } else if (order.count < 1 | order.count > 100000) {
            throw WrongFormatException("Кількість коробок повинна бути між 1 і 100000");
        }
    } else {
        is.setstate(std::ios::failbit);

        if (!is.eof()) {
            throw WrongFormatException("Неправильний формат вводу.");
        }
    }

    return is;
}

void MonthlyRecord::addOrder(Order* order) {
    orders.push_back(order);
}

void MonthlyRecord::removeOrder(size_t row) {
    if (row >= orders.size()) {
        std::string what = "Can't remove the order from row "
                           + std::to_string(row)
                           + " while max available is current size - 1 ("
                           + std::to_string(orders.size() - 1)
                           + ").";
        throw std::out_of_range(what);
    }

    orders.erase(orders.begin() + row);
}

Order* MonthlyRecord::getOrder(int row) {
    return orders[row];
}

std::vector<Order*> MonthlyRecord::getOrders() {
    return orders;
}

void MonthlyRecord::clearRecord() {
    orders.clear();
}

void MonthlyRecord::calculateOutcomes() {
    salaries = 2000; // base salary
    amortization = 0;
    tax = 0;

    for (Order* order : orders) {
        double orderSalaries = order->getMaterialCost() * 0.1;
        double orderAmortization = order->getMaterialCost() * 0.13567;
        double orderTax = (order->getMaterialCost() + orderSalaries + orderAmortization) * 0.21;
        order->setCost(std::ceil((order->getMaterialCost() + orderSalaries + orderAmortization + orderTax) * 100) / 100);

        salaries += orderSalaries;
        amortization += orderAmortization;
        tax += orderTax;
    }

    salaries = std::ceil(salaries * 100) / 100;
    amortization = std::ceil(amortization * 100) / 100;
    tax = std::ceil(tax * 100) / 100;
}

double MonthlyRecord::getIncome() {
    calculateOutcomes();
    double outcome = communalServices + tax + amortization + salaries;
    double grossincome = 0;

    for (Order* order : orders) {
        outcome += order->getMaterialCost();
        grossincome += order->getCost() * 1.1;
    }

    income = std::round((grossincome - outcome) * 100.0) / 100.0;
    return income;
}

double MonthlyRecord::getSalaries() const {
    return salaries;
}

double MonthlyRecord::getCommunalServices() const {
    return communalServices;
}

double MonthlyRecord::getTax() const {
    return tax;
}

double MonthlyRecord::getAmortization() const {
    return amortization;
}

void MonthlyRecord::setOutputCalculations(bool newMode) {
    outputCalculations = newMode;
}

std::ostream& operator<<(std::ostream& os, const MonthlyRecord& record) {
    for (Order* order : record.orders) {
        os << *order;

        if (record.outputCalculations) {
            os << "\tМ: " << order->getMaterialCost()
               << " грн\tС: " << order->getCost()
               << " грн\tЦ: " << order->getCost() * 1.1 << " грн";
        }

        os << '\n';
    }

    if (record.outputCalculations) {
        os << "\nВитрати:\nКомунальні послуги: " << record.communalServices << " грн\n"
           << "Зарплата: " << record.salaries << " грн\n"
           << "Податки: " << record.tax << " грн\n"
           << "Амортизація обладнання: " << record.amortization << " грн\n"
           << "\nМісячний прибуток: " << record.income << " грн\n";
    }

    return os;
}

std::istream& operator>>(std::istream& is, MonthlyRecord& record) {
    std::vector<Order*> newOrders;
    Order* order = new Order();

    std::string dummy;

    while (is >> *order) {
        newOrders.push_back(order);
        order = new Order();
        std::getline(is, dummy);

        if (!std::isdigit(is.peek())) {
            break;
        }
    }

    delete order;
    record.orders = newOrders;
    return is;
}
