#include <iostream>
#include <TGraph.h>
#include <TCanvas.h>

using namespace std;

// Define a hypothetical function for dσ/dt
double CalculateDSigmaDT(double t) {
    // Replace this with your actual calculation
    return 1.0 / (1.0 + t*t); // Example function
}

int main() {
    // Number of points for the plot
    const int nPoints = 100;
    
    // Arrays to store t and dσ/dt values
    double tValues[nPoints];
    double dsigmaDTValues[nPoints];
    
    // Fill the arrays with data
    for (int i = 0; i < nPoints; ++i) {
        tValues[i] = -5.0 + i * 0.1; // Adjust the range and step size as needed
        dsigmaDTValues[i] = CalculateDSigmaDT(tValues[i]);
    }
    
    // Create a TGraph
    TGraph *graph = new TGraph(nPoints, tValues, dsigmaDTValues);
    
    // Create a canvas to display the graph
    TCanvas *canvas = new TCanvas("canvas", "dσ/dt Plot", 800, 600);
    
    // Set axis labels
    graph->GetXaxis()->SetTitle("t");
    graph->GetYaxis()->SetTitle("dσ/dt");
    
    // Draw the graph
    graph->Draw("AL"); // AL: Draw as a line
    
    // Display the canvas
    canvas->Draw();
    
    // Enter the ROOT event loop
    gApplication->Run();
    
    return 0;
}
