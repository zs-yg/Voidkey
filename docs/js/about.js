export function loadAboutContent() {
    const contentElement = document.getElementById('content');
    
    const section = document.createElement('section');
    section.innerHTML = `
        <h2>关于密码工具</h2>
        <div class="about-info">
            <p>版本: 5.0.0</p>
            <p>开发日期: 2025年6月1日</p>
            <p>开发者: VoidKey团队</p>
            <p>技术栈: GTK4, C语言</p>
        </div>
    `;
    
    contentElement.appendChild(section);
}
