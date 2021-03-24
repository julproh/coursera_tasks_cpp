#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Image
{
    double quality;
    double freshness;
    double rating;
};

struct Params
{
    double a;
    double b;
    double c;
};

class FunctionPart {
    public:
    FunctionPart(char new_operation, double new_value) {
        operation = new_operation;
        value = new_value;
    }
    double Apply (double source_value) const {
        if (operation == '+') {
            return source_value + value;
        } else {
            return source_value - value;
        }
    }
    void Invert() {
        if (operation == '+'){
            operation = '-';
        } else {
            operation = '+';
        }
    }
    private:
    char operation;
    double value;
};
class Function {
    public: 
    void AddPart(char operation, double value) {
        parts.push_back({operation, value});
    }
    double Apply(double value) const {
        for (const FunctionPart& part : parts) {
            value = part.Apply(value);
        }
    }
    void Invert(){
        for (FunctionPart& part : parts) {
            part.Invert();
        }
        reverse(begin(parts), end(parts));
    }
private:
vector <FunctionPart> parts;
};

Function MakeWeightFunction (const Params& params,
                             const Image& image) {
    Function function;
    function.AddPart('-', image.freshness* params.a + params.b);
    function.AddPart('+', image.rating * params.c);
    return function;
}

double ComputeImageWieght (const Params& params, const Image& image) {
   Function function = MakeWeightFunction(params, image);
   return function.Apply(image.quality);
   /* double wieght = image.quality;
    wieght -= image.freshness * params.a + params.b;
    wieght += image.rating*params.c; 
    return wieght;*/
}

double ComputeQualityByweight (const Params& params,
                               const Image& image,
                               double weight) {
    Function function = MakeWeightFunction(params, image);
    function.Invert();
    return function.Apply(weight);
    /*double quality = weight;
    quality -= image.rating * params.c;
    quality += image.freshness*params.a + params.b;
    return quality; */
}
int main() {
    Image image = {10, 2, 6};
    Params params = {4, 2, 6};
    // wiegth == 36;
    cout << ComputeImageWieght(params, image) << endl;
    cout << ComputeQualityByweight(params, image, 46) << endl;
    return 0;
}