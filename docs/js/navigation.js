const navItems = [
    { title: '首页', id: 'home' },
    { title: '功能介绍', id: 'features' },
    { title: '使用指南', id: 'guide' },
    { title: '关于', id: 'about' }
];

export function initNavigation() {
    const navElement = document.getElementById('main-nav');
    
    navItems.forEach(item => {
        const link = document.createElement('a');
        link.href = `#${item.id}`;
        link.textContent = item.title;
        link.classList.add('nav-link');
        navElement.appendChild(link);
    });
}
