using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _0426_지도
{
    class LocationData
    {
        public string Title { get; set; }
        public double Latitude { get; set; }
        public double Longitude { get; set; }

        public LocationData(string title, double lat, double lng)
        {
            Title = title;
            Latitude = lat;
            Longitude = lng;
        }
    }
}
