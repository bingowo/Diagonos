#include "filters.h"
#include <vector>
#include <cmath>

using std::vector;

// Convert image to grayscale
void grayscale(vector<vector<RGBTRIPLE>>& image)
{
    for(auto &line:image)
    {
        for(auto &p:line)
        {
            p.rgbtRed = (p.rgbtRed + p.rgbtGreen + p.rgbtBlue) / 3.0;
            p.rgbtGreen = p.rgbtRed;
            p.rgbtRed = p.rgbtRed;
        }
    }
}
// Convert image to sepia
void sepia(vector<vector<RGBTRIPLE>>& image)
{
    for (int i = 0; i < image.size(); i++)
    {
        for (int j = 0; j < image[i].size(); j++)
        {
            int sepiaR = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            int sepiaG = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            int sepiaB = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

            image[i][j].rgbtRed = (sepiaR > 255) ? 255 : sepiaR;
            image[i][j].rgbtGreen = (sepiaG > 255) ? 255 : sepiaG;
            image[i][j].rgbtBlue = (sepiaB > 255) ? 255 : sepiaB;
        }
    }
}

// Reflect image horizontally
void reflect(vector<vector<RGBTRIPLE>>& image)
{
    for (int i = 0; i < image.size(); i++)
    {
        if (image[i].size() % 2 == 0)
        {
                for (int j = 0; j < image[i].size() / 2; j++)
            {
                RGBTRIPLE help[image.size()][image[i].size()];

                help[i][j] = image[i][j];
                image[i][j] = image[i][image[i].size() - 1 - j];
                image[i][image[i].size() - 1 - j] = help[i][j];
            }
        }

        if (image[i].size() % 2 == 1)
        {
                for (int j = 0; j < (image[i].size() - 1) / 2; j++)
            {
                RGBTRIPLE help[image.size()][image[i].size()];

                help[i][j] = image[i][j];
                image[i][j] = image[i][image[i].size() - 1 - j];
                image[i][image[i].size() - 1 - j] = help[i][j];
            }
        }
    }
}
// Blur image
void blur(vector<vector<RGBTRIPLE>>& image);

