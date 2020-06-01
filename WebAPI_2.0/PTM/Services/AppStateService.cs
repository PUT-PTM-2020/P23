using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace PTM.Services
{
    public class AppStateService
    {
        /// <summary>
        /// First string: DeviceId,
        /// Second string: Screen string
        /// Third string: Card Id
        /// </summary>
        public Action<string, string, string> OnDisplayChange;

        /// <summary>
        /// First string: DeviceId,
        /// Second string: Key pressed
        /// </summary>
        public Action<string, string> OnKeyPress;

        /// <summary>
        /// First string: DeviceId,
        /// Second string: Toast Type
        /// Third string: Message to show
        /// </summary>
        public Action<string, string, string> OnToastAction;
    }
}
