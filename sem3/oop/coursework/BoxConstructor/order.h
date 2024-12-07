#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <unordered_map>

enum Material {
    Undefined,
    CorrugatedCardboard, // 0.99
    SolidCardboard, // 2.49
    Wood, // 8.99
    Biodegradable, // 3.99
    Plastic // 1.79
};

class Order {
public:
    Order();
    Order(unsigned int length, unsigned int width, unsigned int height, Material material, unsigned int count);
    Order(const Order& other);
    Order(Order&& other) noexcept;
    Order& operator=(const Order& other);
    Order& operator=(Order&& other) noexcept;

    ~Order() = default;

    unsigned int getLength() const;
    void setLength(unsigned int newLength);
    unsigned int getWidth() const;
    void setWidth(unsigned int newWidth);
    unsigned int getHeight() const;
    void setHeight(unsigned int newHeight);
    Material getMaterial() const;
    void setMaterial(Material newMaterial);
    unsigned int getCount() const;
    void setCount(unsigned int newCount);

    double getMaterialCost();
    double getCost();
    void setCost(double newCost);

    static double getPrice(Material material);
    static void setPrice(Material material, double newPrice);

    friend std::ostream& operator<<(std::ostream& os, const Order& order);
    friend std::istream& operator>>(std::istream& is, Order& order);

private:
    unsigned int length;
    unsigned int width;
    unsigned int height;
    Material material;
    unsigned int count;

    double cost;
    static std::unordered_map<Material, double> prices;
};

std::string materialToString(Material material);

Material stringToMaterial(const std::string& str);

std::ostream& operator<<(std::ostream& os, const Order& order);

std::istream& operator>>(std::istream& is, Order& order);

class MonthlyRecord {
public:
    void addOrder(Order* order);
    void removeOrder(size_t row);
    Order* getOrder(int row);
    std::vector<Order*> getOrders();
    void clearRecord();
    void calculateOutcomes();
    double getIncome();

    double getSalaries() const;
    double getCommunalServices() const;
    double getTax() const;
    double getAmortization() const;
    void setOutputCalculations(bool newMode);

    friend std::ostream& operator<<(std::ostream& os, const MonthlyRecord& record);
    friend std::istream& operator>>(std::istream& is, MonthlyRecord& record);

private:
    const double communalServices = 2500;
    double salaries;
    double tax;
    double amortization;
    double income;

    std::vector<Order*> orders;
    bool outputCalculations;
};

std::ostream& operator<<(std::ostream& os, const MonthlyRecord& record);

std::istream& operator>>(std::istream& is, MonthlyRecord& record);

#endif // ORDER_H
